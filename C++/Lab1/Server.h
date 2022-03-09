#include "IServer.h"

class Server : public IServer, public IServer2 {
    public:
        void Func();
        void Func2();
        int QueryInterface(int iid, void** ppv);
};

class Server2 :public IServer, public IServer2 {
    public:
        void Func();
        void Func2();
        int QueryInterface(int iid, void** ppv);
};

IUnknown* CreateInstance(int serverID);