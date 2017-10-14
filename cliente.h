//
// Created by maesly on 17/09/17.
//
/**
 * @file cliente.h
 * @class Cliente
 * @brief En este archivo se hacen las declaraciones de las variables
 * y de las funciones que se implementaran en el archivo cliente.cpp
 * @author Maesly V.
 * */
#ifndef CLIENTE_CLIENTE_H
#define CLIENTE_CLIENTE_H

#include <netinet/in.h>

class Cliente{
private:
    int cliente;                        /// socket
    int port = 6060;                    // numero de puerto del servidor
    bool salir = false;                 // booleano para mantener el while
    const int bufsize = 1024;           // tamaño de las palabras
    char* buffer = new char(bufsize);   // son los char que se van a enviar y recibir
    const char *ip = "127.0.0.1";       /// Direccion ip del servidor
    char a;

    struct sockaddr_in server_addr;
    socklen_t size;

public:

    Cliente(sockaddr_in server_addr);
    ~Cliente();
    void iniciar();
    void ejecutar();
    void detener();

};
#endif //CLIENTE_CLIENTE_H
