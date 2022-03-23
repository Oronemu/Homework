#include <iostream>
#include "Interfaces.h"

class Server : public IServer, public IServer2 {
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(I_ID iid, void** ppv);
};

class Server2 : public IServer, public IServer2 {
public:
    void Func();
    void Func2();
    H_RESULT QueryInterface(I_ID iid, void** ppv);
};

void Server::Func() {
    std::cout << "Server 1 Interface 1" << std::endl;
}

void Server::Func2() {
    std::cout << "Server 1 Interface 2" << std::endl;
}

H_RESULT Server::QueryInterface(I_ID iid, void** ppv) {
    switch (iid) {
        case IID_IUnknown: {
            *ppv = (IUnknown*) (IServer*) this;
            break;
        }
        case IID_IServer: {
            *ppv = (IServer*) this;
            break;
        }
        case IID_IServer2: {
            *ppv = (IServer2*) this;
            break;
        }
        default: {
            *ppv = NULL;
            return E_NOINTERFACE;
        }
    }
    return S_OK;
}

H_RESULT IServerFactory::CreateInstance(I_ID iid, void** ppv) {
    Server* server = new Server();
    if (server == 0) {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = server->QueryInterface(iid, ppv);
    return res;
}

H_RESULT IServerFactory::QueryInterface(I_ID iid, void** ppv) {
    if (iid == IID_IUnknown || iid == IID_IClassFactory) {
        *ppv = (IClassFactory*) this;
    }
    else {
        *ppv = 0;
        return E_NOINTERFACE;
    }
    return S_OK;
}

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv) {
    if(clsid != CLSIDServer) {
        return E_CLASSNOTAVAILABLE;
    }
    IServerFactory* factory = new IServerFactory();
    if(factory == 0) {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = factory->QueryInterface(iid, ppv);
    return res;
}