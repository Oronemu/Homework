#include "IUnknown.h"

class IServer : public IUnknown {
public:
    virtual void Func() = 0;
};

class IServer2 : public IUnknown {
public:
    virtual void Func2() = 0;
};

class IServerFactory : public IClassFactory  {
    public:
        IServerFactory() {};
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        H_RESULT CreateInstance(I_ID iid, void** ppv);
};

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv);