typedef int H_RESULT;
typedef int I_ID;
typedef int CLS_ID;
typedef int U_LONG;

const H_RESULT S_OK = 1111;
const H_RESULT E_NOINTERFACE = -1;
const H_RESULT E_OUTOFMEMORY = -2;
const H_RESULT E_CLASSNOTAVAILABLE = -3;

class IUnknown {
    public:
        virtual H_RESULT QueryInterface(I_ID iid, void** ppv) = 0;
        virtual U_LONG AddRef() = 0;
        virtual U_LONG Release() = 0;
};

class IClassFactory : public IUnknown {
    private:
        int countReference = 0;
    public:
        virtual H_RESULT CreateInstance(I_ID iid, void** ppv) = 0;
        U_LONG AddRef();
        U_LONG Release();
};