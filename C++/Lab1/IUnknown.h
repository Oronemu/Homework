typedef int H_RESULT;
typedef int I_ID;
typedef int CLS_ID;

const I_ID IID_IUnknown = 0;
const I_ID IID_IServer = 1;
const I_ID IID_IServer2 = 2;
const I_ID IID_IClassFactory = 10;
const H_RESULT S_OK = 1111;
const H_RESULT E_NOINTERFACE = -1;
const H_RESULT E_OUTOFMEMORY = -2;
const H_RESULT E_CLASSNOTAVAILABLE = -3;
const CLS_ID CLSIDServer = 101;

class IUnknown {
    public:
        virtual H_RESULT QueryInterface(I_ID iid, void** ppv) = 0;
};

class IClassFactory : public IUnknown {
    public:
        virtual H_RESULT CreateInstance(I_ID iid, void** ppv) = 0;
};