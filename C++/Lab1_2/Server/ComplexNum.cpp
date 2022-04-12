#include "ComplexNum.h"
#include <iostream>

ComplexNum::ComplexNum() {
    real = 0;
    img = 0;
}

ComplexNum::ComplexNum(int real, int img) {
    this->real = real;
    this->img = img;
}

void ComplexNum::print() {
    if (img < 0) {
        if (img == -1) std::cout << "Комплекное число: "<< real << "-i" << std::endl;
        else std::cout << "Комплекное число: "<< real << img << "i" << std::endl;
    } else {
        if(img == 1) std::cout << "Комплекное число: "<< real << " + i"<< std::endl;
        else std::cout << "Комплекное число: "<< real << " + " << img << "i" << std::endl;
    }
}

ComplexNum add(ComplexNum num1, ComplexNum num2) {
    ComplexNum result;
    result.real = num1.real + num2.real;
    result.img = num1.img + num2.img;
    return result;
}

ComplexNum sub(ComplexNum num1, ComplexNum num2) {
    ComplexNum result;
    result.real = num1.real - num2.real;
    result.img = num1.img - num2.img;
    return result;
}

U_LONG ComplexNum::AddRef() {
    countReference++;
    return countReference;
}

U_LONG ComplexNum::Release() {
    countReference--;
    if(countReference == 0) {
        delete this;
    }
    return countReference;
}

H_RESULT ComplexNum::QueryInterface(I_ID iid, void** ppv) {
    switch (iid) {
        case IID_IUnknown: {
            *ppv = (IUnknown*) (IPrintComplexNum*) this;
            break;
        }
        case IID_IAddComplexNum: {
            *ppv = (IAddComplexNum*) this;
            break;
        }
        case IID_ISubComplexNum: {
            *ppv = (ISubComplexNum*) this;
            break;
        }
        case IID_IPrintComplexNum: {
            *ppv = (IPrintComplexNum*) this;
            break;
        }
        default: {
            *ppv = 0;
            return E_NOINTERFACE;
        }
    }
    AddRef();
    return S_OK;
}

ComplexNumFactory::ComplexNumFactory() {}

U_LONG ComplexNumFactory::AddRef() {
    countReference++;
    return countReference;
}

U_LONG ComplexNumFactory::Release() {
    countReference--;
    if(countReference == 0) {
        delete this;
    }
    return countReference;
}

H_RESULT ComplexNumFactory::CreateInstance(I_ID iid, void** ppv, int real, int img) {
    ComplexNum* complexNum = new ComplexNum(real, img);
    if (complexNum == 0) {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = complexNum->QueryInterface(iid, ppv);
    return res;
}

H_RESULT ComplexNumFactory::QueryInterface(I_ID iid, void** ppv) {
    if (iid == IID_IUnknown || iid == IID_IClassFactory) {
        *ppv = (IClassFactory*) this;
    }
    else {
        *ppv = 0;
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv) {
    if(clsid != CLSIDComplex) {
        return E_CLASSNOTAVAILABLE;
    }
    ComplexNumFactory* factory = new ComplexNumFactory();
    if(factory == 0) {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = factory->QueryInterface(iid, ppv);
    return res;
}

ComplexNumWrapper::ComplexNumWrapper(int real, int img) {
    GetClassObject(CLSIDComplex, IID_IClassFactory, (void**)&factory);
    factory->CreateInstance(IID_IAddComplexNum, (void**)&iAddComplexNum, real, img);
    factory->Release();
    iAddComplexNum->QueryInterface(IID_IPrintComplexNum, (void**)&iPrintComplexNum);
}


ComplexNumWrapper::~ComplexNumWrapper() {
    iAddComplexNum->Release();
    iPrintComplexNum->Release();
    iSubComplexNum->Release();
}

void ComplexNumWrapper::print() {
    iPrintComplexNum->print();
}

ComplexNum ComplexNumWrapper::sub(ComplexNum num1, ComplexNum num2) {
    iSubComplexNum->sub(num1, num2);
}

ComplexNum ComplexNumWrapper::add(ComplexNum num1, ComplexNum num2) {
    iAddComplexNum->add(num1, num2);
}


