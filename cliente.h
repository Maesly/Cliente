//
// Created by maesly on 17/09/17.
//

#ifndef CLIENTE_CLIENTE_H
#define CLIENTE_CLIENTE_H

#include <netinet/in.h>

class Cliente{
private:
    int client;
    char a;
    int port = 8080;
    bool isExit = false;
    const int bufsize = 1024;
    char* buffer = new char(bufsize);
    //char*ip;
    //strcpy(ip,"127.0.0.1");
    const char *ip = "127.0.0.1";
    struct sockaddr_in server_addr;
    socklen_t size;
public:
    Cliente(sockaddr_in server_addr);
    ~Cliente();
    void begin();
    void run();
    void stop();
};
#endif //CLIENTE_CLIENTE_H
