#ifndef ISERVER_H
#define ISERVER_H

class IServer {
    public:
    virtual void func(int c) = 0; 
};

IServer* CreateInstance(int choice);

#endif 