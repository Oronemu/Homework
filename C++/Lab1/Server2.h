#ifndef SERVER2_H
#define SERVER2_H

#include "IServer.h"

class Server2: public IServer {
    private:
        int a;
        int b;
    public: 
        Server2();
        ~Server2();
        void func(int c);
        void func2();
};

#endif 