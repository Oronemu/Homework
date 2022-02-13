#ifndef ISERVER_H
#define ISERVER_H

class IServer {
    public:
    virtual void func() = 0; 
};

IServer* CreateInstance();

#endif 