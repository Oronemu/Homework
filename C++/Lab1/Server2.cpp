#include "Server2.h"
#include <iostream>

void Server2::func(int c) {
    std::cout << "Func1 - " << (a + b) * c << "\n";
}

void Server2::func2() {
    std::cout << "Func2 - " << (a + b) << "\n";
}

Server2::Server2() {
    a = 5;
    b = 1;
}

Server2::~Server2() {
    std::cout << "Destructor";
}

