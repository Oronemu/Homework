#include "IServer.h"

int main() {
    IServer* server = CreateInstance();
    server->func();
    return 0;
}