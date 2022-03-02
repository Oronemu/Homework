#include "Server.h"
#include <iostream>

void Server::func(int c) {
    std::cout << "Func1 - " << (a + b) * c << "\n";
}

void Server::func2() {
    std::cout << "Func2 - " << (a + b) << "\n";
}

Server::Server() {
    a = 2;
    b = 10;
}

Server::~Server() {
    std::cout << "Destructor";
}

