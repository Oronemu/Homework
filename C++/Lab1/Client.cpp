#include <iostream>
#include "Interfaces.h"

using namespace std;
int main() {
    IServerFactory* serverFactory;
    IServer2* iServer;
    H_RESULT res = GetClassObject(CLSIDServer, IID_IClassFactory, (void**)&serverFactory);
    if(res != S_OK) return res;
    res = serverFactory->CreateInstance(IID_IServer2, (void**)&iServer);
    if(res != S_OK) return res;
    iServer->Func2();
}