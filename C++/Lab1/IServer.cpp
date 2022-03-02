#include "Server.h"
#include "Server2.h"
#include "IServer.h"

IServer* CreateInstance(int choice){
    switch (choice) {
    case 1:
        return new Server();
        break;
    case 2: 
        return new Server2();
        break;
    default:
        break;
    }
}

