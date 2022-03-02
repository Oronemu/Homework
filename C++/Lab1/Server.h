#ifndef SERVER_H
#define SERVER_H
#include "IServer.h"
#include "IServer2.h"

class Server: public IServer, public IServer2 {
    private:
        int a;
        int b;
    public: 
        Server();
        ~Server();
        void func(int c);
        void func2();
};

#endif 