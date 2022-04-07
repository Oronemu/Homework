#include "ComplexNum.h"
#include <iostream>

class ComplexNum: IAddComplexNum, IGetComplexNum, ISetComplexNum, ISubComplexNum {
    private:
        int countReference = 0;
        int real, img;
    public:
        ComplexNum();
        ComplexNum(int real, int img);
        H_RESULT QueryInterface(I_ID iid, void** ppv);
        U_LONG AddRef();
        U_LONG Release();
        ComplexNum add(ComplexNum, ComplexNum);
        ComplexNum sub(ComplexNum, ComplexNum);
        void setComplexNum();
        void getComplexNum();
};

ComplexNum::ComplexNum() {
    real = 0;
    img = 0;
}

ComplexNum::ComplexNum(int real, int img) {
    this->real = real;
    this->img = img;
}

void ComplexNum::setComplexNum(){
    std::cout << "Введите вещественное число: ";
    std::cin >> real;
    std::cout << "Введите мнимое число: ";
    std::cin >> img;
}

void ComplexNum::getComplexNum() {
    std::cout << "Комплексное число: "<< real << "+" << img << "i" << std::endl;
}

ComplexNum ComplexNum::add(ComplexNum num1, ComplexNum num2) {
    ComplexNum result;
    result.real = num1.real + num2.real;
    result.img = num1.img + num2.img;
    return result;
}

ComplexNum ComplexNum::sub(ComplexNum num1, ComplexNum num2) {
    ComplexNum result;
    result.real = num1.real - num2.real;
    result.img = num1.img - num2.img;
    return result;
}

U_LONG ComplexNum::AddRef() 
{
    countReference++;
    return countReference;
}

U_LONG ComplexNum::Release() 
{
    countReference--;
    if(countReference == 0)
    {
        delete this;
    }
    return countReference;
}

H_RESULT ComplexNum::QueryInterface(I_ID iid, void** ppv)
{
    switch (iid)
    {
        case IID_IUnknown:
        {
            *ppv = (IUnknown*) (ISetComplexNum*) this;
            break;
        }
        case IID_IAddComplexNum:
        {
            *ppv = (IAddComplexNum*) this;
            break;
        }
        case IID_ISubComplexNum:
        {
            *ppv = (ISubComplexNum*) this;
            break;
        }
        case IID_ISetCompexNum:
        {
            *ppv = (ISetComplexNum*) this;
            break;
        }
        case IID_IGetCompexNum:
        {
            *ppv = (IGetComplexNum*) this;
            break;
        }
        default:
        {
            *ppv = 0;
            return E_NOINTERFACE;
        }
    }
    AddRef();
    return S_OK;
}

ComplexNumFactory::ComplexNumFactory() {}

U_LONG ComplexNumFactory::AddRef() 
{
    countReference++;
    return countReference;
}

U_LONG ComplexNumFactory::Release() 
{
    countReference--;
    if(countReference == 0)
    {
        delete this;
    }
    return countReference;
}

H_RESULT ComplexNumFactory::CreateInstance(I_ID iid, void** ppv, int real, int img)
{
    ComplexNum* complexNum = new ComplexNum(real, img);
    if (complexNum == 0)
    {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = complexNum->QueryInterface(iid, ppv);
    return res;
}

H_RESULT ComplexNumFactory::QueryInterface(I_ID iid, void** ppv)
{
    if (iid == IID_IUnknown || iid == IID_IClassFactory)
    {
        *ppv = (IClassFactory*) this;
    }
    else
    {
        *ppv = 0;
        return E_NOINTERFACE;
    }
    AddRef();
    return S_OK;
}

H_RESULT GetClassObject(CLS_ID clsid, I_ID iid, void** ppv)
{
    if(clsid != CLSIDColor)
    {
        return E_CLASSNOTAVAILABLE;
    }
    ComplexNumFactory* factory = new ComplexNumFactory();
    if(factory == 0) 
    {
        return E_OUTOFMEMORY;
    }
    H_RESULT res = factory->QueryInterface(iid, ppv);
    return res;
}

ComplexNumWrapper::ComplexNumWrapper(int real, int img)
{
    GetClassObject(CLSIDColor, IID_IClassFactory, (void**)&factory);
    factory->CreateInstance(IID_ISetCompexNum, (void**)&iSetComplexNum, real, img);
    factory->Release();
    iSetComplexNum->QueryInterface(IID_IGetCompexNum, (void**)&iGetComplexNum);
}


ComplexNumWrapper::~ComplexNumWrapper() 
{
    iSetComplexNum->Release();
    iAddComplexNum->Release();
    iGetComplexNum->Release();
    iSubComplexNum->Release();
}

void ComplexNumWrapper::setComplexNum()
{
    iSetComplexNum->setComplexNum();
}

void ComplexNumWrapper::getComplexNum()
{
    iGetComplexNum->getComplexNum();
}

ComplexNum ComplexNumWrapper::sub(ComplexNum num1, ComplexNum num2)
{
    iSubComplexNum->sub(num1, num2);
}


ComplexNum ComplexNumWrapper::add(ComplexNum num1, ComplexNum num2)
{
    iAddComplexNum->add(num1, num2);
}


