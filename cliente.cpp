//
// Created by maesly on 17/09/17.
//

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include "cliente.h"

using namespace std;

/**
 * Constructor de la clase
 */

Cliente::Cliente(sockaddr_in server_addr) {
    isExit = false;
}

/**
 *Detiene el servidor
 */

void Cliente::stop() {
    isExit = true;
    shutdown(client,SHUT_RDWR);
}

/**
*Inicializador
*/

void Cliente::begin() {
    client= socket(AF_INET,SOCK_STREAM,0);
    run();
}
/**
 * Destructor de la clase
 */

Cliente::~Cliente(){}
/**
 * Metodo principal para conectarse al servidor
 * */
void Cliente::run() {

    if(client<0){
        cout <<"Error al crear el socket cliente";
        exit(0);
    }
    cout<<"Escriba # para acabar la comunicacion" << endl;
    cout<< "\t\t\t [s] para empezar";
    cin>>a;

    cout << "Socket creado"<< endl;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET,ip,&server_addr.sin_addr);

    if(connect(client,(struct sockaddr *) &server_addr,sizeof(server_addr))==0)
        cout << "Conexion con el servidor\n"<< inet_ntoa(server_addr.sin_addr)<<endl;

    cout << "Esperando confirmacion del servidor "<< endl;
    recv(client,buffer,bufsize,0);

    cout<< "Respuesta recibida"<< buffer;
    cout<< "\n Poner * al final de cada mensaje \n Escriba # para terminar la conexion\n";

    do{
        cout<< "Escribir mensaje: ";
        do{
            cin>> buffer;
            send(client,buffer,bufsize,0);
            if(*buffer == '#'){
                send(client,buffer,bufsize,0);
                *buffer = '*';
                isExit = true;

            }
        }while(*buffer != 42);
        cout<< "Mensaje recibido: ";
        do{
            recv(client,buffer,bufsize,0);
            cout<< buffer<<" ";
            if(*buffer ==  '#'){
                *buffer = '*';
                isExit = true;

            }
        }while(*buffer != 42);
        cout<<endl;
    }while(!isExit);
    cout<< "Conexion terminada. Programa finalizado\n\n";
    close(client);
    return;
}