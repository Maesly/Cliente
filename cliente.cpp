//
// Created by maesly on 17/09/17.
//
/**
 * @file cliente.cpp
 * @author Maesly V.
 * */

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
 * @brief Constructor de la clase
 */

Cliente::Cliente(sockaddr_in server_addr) {
    salir = false;
}

/**
 *@brief Metodo que detiene el servidor
 */

void Cliente::detener() {
    salir = true;
    shutdown(cliente,SHUT_RDWR);
}

/**
*@brief Metodo que inicializa el socket y llama la funcion ejecutar()
*/

void Cliente::iniciar() {
    cliente= socket(AF_INET,SOCK_STREAM,0); //Crea el socket cliente
    ejecutar(); //ejecutala funcion
}
/**
 * @brief Destructor de la clase
 */

Cliente::~Cliente(){}
/**
 * @brief Metodo principal para conectarse al servidor
 * */
void Cliente::ejecutar() {

    if(cliente<0){
        cout <<"Error al crear el socket cliente";
        exit(0);
    }
    //cout<<"Escriba # para acabar la comunicacion" << endl;
    //cout<< "\t\t\t [s] para empezar";
   // cin>>a;

    cout << "Socket creado"<< endl;
    server_addr.sin_family = AF_INET;               //asinar a la estructura sockaddr un dominio, ip y puerto
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET,ip,&server_addr.sin_addr);

    if(connect(cliente,(struct sockaddr *) &server_addr,sizeof(server_addr))==0)
        cout << "Conexion con el servidor\n"<< inet_ntoa(server_addr.sin_addr)<<endl;


    while (!salir){
        cout << "\tOprima 1 para insertar elemento\n";
        cout << "\tOprima 2 para buscar elemento\n";
        cout << "\tOprima 3 para eliminar elemento\n";
        cin>>buffer;

        if(*buffer =='salir'){
            send(cliente,buffer,bufsize,0);
            cout<<*buffer;
        }
        else if(*buffer == '1'){

            //cout<< "Inserte un dato:\n";
            //cin>>buffer;
            send(cliente,buffer,bufsize,0);
            cout << *buffer;
        }
        else if(*buffer == '2'){
            send(cliente,buffer,bufsize,0);
            cout << *buffer;
        }
        else if(*buffer == '3') {
            send(cliente, buffer, bufsize, 0);
            cout << *buffer;
        }
        else{
            send(cliente,buffer,bufsize,0);
        }
        }
        //strcpy(buffer,"HOLIS");

        //exit(0);
}