#ifndef SERVER_H
#define SERVER_H
#include "IServer.h"

class Server: public IServer {
    private:
        int a;
        int b;
    public: 
        Server();
        ~Server();
        void func();
};

#endif 