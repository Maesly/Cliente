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
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Cliente* cliente = new Cliente(sockaddr_in());
    cliente->begin();

    return 0;

}

