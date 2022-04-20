#include "../Server/ComplexNum.h"
#include <iostream>
#include <dlfcn.h>

using namespace std;

typedef H_RESULT (*GetClass) (CLS_ID clsid, I_ID iid, void** ppv);

int main(int argc, char const *argv[]) {

    // void *h;	// хандлер внешней библиотеки
    // GetClass f;	// переменная для хранения адреса функции

	// h = dlopen("/Users/ivanrovkov/Desktop/Homework/C++/Lab1_2/Build/ComplexNum.so",RTLD_LAZY);
	// if (!h){
	// 	fprintf(stderr, "Error while dlopen(): %s\n", dlerror());
	// 	return 1;
	// }

    // f = (GetClass) dlsym(h, "GetClassObject");

    // if (!f) {
    //     cout << "No dll function" << endl;
    //     return 0;
    // } 

    ComplexNumFactory* ppv;
    IPrintComplexNum* iP;
    // f(CLSIDComplex, IID_IClassFactory, (void**)&ppv);
    ppv->CreateInstance(IID_IPrintComplexNum, (void**)&iP, 120, 230);
    iP->print();

	return 0;
}