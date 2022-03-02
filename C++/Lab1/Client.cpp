#include "IServer.h"
#include "IServer2.h"

int main() {
    IServer* server = CreateInstance(2);
    IServer2* server2 = (IServer2* ) server;
    server2->func2();
    return 0;
}