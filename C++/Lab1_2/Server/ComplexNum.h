#include "IUnknown.h"

const I_ID IID_IUnknown = 0;
const I_ID IID_IClassFactory = 10;

const CLS_ID CLSIDColor = 101;

const I_ID IID_IAddComplexNum = 1;
const I_ID IID_ISubComplexNum = 2;
const I_ID IID_IGetCompexNum = 3;
const I_ID IID_ISetCompexNum = 4;

class IAddComplexNum: public IUnknown {
public:
    virtual ComplexNum add(ComplexNum, ComplexNum) = 0;
};

class ISubComplexNum: public IUnknown {
public:
    virtual ComplexNum sub(ComplexNum, ComplexNum) = 0;
};

class IGetComplexNum: public IUnknown {
public:
    virtual void getComplexNum() = 0;
};

class ISetComplexNum: public IUnknown {
public:
    virtual void setComplexNum() = 0;
};

class ComplexNumFactory : public IUnknown
{
    private:
        int countReference = 0;
    public:
        H_RESULT CreateInstance(I_ID iid, void** ppv, int real, int img);
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        U_LONG AddRef();
        U_LONG Release();
        ComplexNumFactory();
};

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv);

class ComplexNumWrapper
{
    private:
        ComplexNumFactory* factory;

        IAddComplexNum* iAddComplexNum;
        ISubComplexNum* iSubComplexNum;
        IGetComplexNum* iGetComplexNum;
        ISetComplexNum* iSetComplexNum;

    public:
        void setComplexNum();
        void getComplexNum();
        ComplexNum add(ComplexNum num1, ComplexNum num2);
        ComplexNum sub(ComplexNum num1, ComplexNum num2);

        ComplexNumWrapper(int real, int img);
        ~ComplexNumWrapper();
};