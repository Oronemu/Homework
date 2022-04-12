#include "IUnknown.h"

const I_ID IID_IUnknown = 0;
const I_ID IID_IClassFactory = 10;

const CLS_ID CLSIDComplex = 101;

const I_ID IID_IAddComplexNum = 1;
const I_ID IID_ISubComplexNum = 2;
const I_ID IID_IPrintComplexNum = 3;

class ComplexNum {
    private:
        int countReference = 0;
        int real, img;
    public:
        ComplexNum();
        ComplexNum(int real, int img);
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        U_LONG AddRef();
        U_LONG Release();
        friend ComplexNum add(ComplexNum, ComplexNum);
        friend ComplexNum sub(ComplexNum, ComplexNum);
        void print();
};

class IAddComplexNum: public IUnknown {
public:
    virtual ComplexNum add(ComplexNum, ComplexNum) = 0;
};

class ISubComplexNum: public IUnknown {
public:
    virtual ComplexNum sub(ComplexNum, ComplexNum) = 0;
};

class IPrintComplexNum: public IUnknown {
public:
    virtual void print() = 0;
};

class ComplexNumFactory: public IUnknown {
    private:
        int countReference = 0;
    public:
        H_RESULT CreateInstance(I_ID iid, void** ppv, int real, int img);
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        U_LONG AddRef();
        U_LONG Release();
        ComplexNumFactory();
};

class ComplexNumWrapper {
    private:
        ComplexNumFactory* factory;
        IAddComplexNum* iAddComplexNum;
        ISubComplexNum* iSubComplexNum;
        IPrintComplexNum* iPrintComplexNum;

    public:
        void print();
        ComplexNum add(ComplexNum num1, ComplexNum num2);
        ComplexNum sub(ComplexNum num1, ComplexNum num2);

        ComplexNumWrapper(int real, int img);
        ~ComplexNumWrapper();
};