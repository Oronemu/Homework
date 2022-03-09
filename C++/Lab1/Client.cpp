#include <iostream>
#include "Server.h"

using namespace std;
int main() {
    int serverID, interfaceID;

    cout << "Выберите сервер: ";
    cin >> serverID;
    cout << "Выберите интерфейс: ";
    cin >> interfaceID;

    IUnknown* IUnknown = CreateInstance(serverID);
    if(IUnknown == NULL) return 0;

    switch (interfaceID) {
    case 1: {
        IServer* iserver;
        if(IUnknown->QueryInterface(1, (void**)& iserver) != -1) {
            iserver->Func();
        }
        else return 0;
        break;
    }
    case 2: {
        IServer2* iserver2;
        if(IUnknown->QueryInterface(2, (void**)& iserver2) != -1) {
            iserver2->Func2();
        }
        else return 0;
        break;
    }
    default: {return 0;}
    }
}