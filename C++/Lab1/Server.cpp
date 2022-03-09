#include "Server.h"
#include <iostream>

void Server::Func() {
    std::cout << "Сервер 1, используется Интерфейс 1" << std::endl;
}

void Server::Func2() {
    std::cout << "Сервер 1, используется Интерфейс 2" << std::endl;
}

int Server::QueryInterface(int iid, void** ppv) {
    switch (iid) {
        case 0: {
            *ppv = (IUnknown*) (IServer*) this;
            return 0;
        }
        case 1: {
            *ppv = (IServer*) this;
            return 1;
        }
        case 2: {
            *ppv = (IServer2*) this;
            return 2;
        }
        default: {
            *ppv = NULL;
            return -1;
        }
    }
}

void Server2::Func() {
    std::cout << "Сервер 2, используется Интерфейс 1" << std::endl;
}

void Server2::Func2() {
    std::cout << "Сервер 2, используется Интерфейс 2" << std::endl;
}

int Server2::QueryInterface(int iid, void** ppv) {
    switch (iid) {
        case 0: {
            *ppv = (IUnknown*) (IServer*) this;
            return 0;
        }
        case 1: {
            *ppv = (IServer*) this;
            return 1;
        }
        case 2: {
            *ppv = (IServer2*) this;
            return 2;
        }
        default: {
            *ppv = NULL;
            return -1;
        }
    }
}

IUnknown* CreateInstance(int serverID) {
    switch (serverID) {
        case 1: {
            Server* server = new Server();
            return (IUnknown*) (IServer*) server;
        }
        case 2: {
            Server2* server = new Server2();
            return (IUnknown*) (IServer*) server;
        }
        default: {
            return NULL;
        }
    }
}