#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include "cliente.h"
#include <pthread.h>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Cliente* cliente = new Cliente(sockaddr_in());
    cliente->iniciar();

    return 0;

}

