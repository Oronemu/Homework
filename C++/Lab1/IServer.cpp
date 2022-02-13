#include "Server.h"
#include "IServer.h"

IServer* CreateInstance(){
    return new Server();
}

