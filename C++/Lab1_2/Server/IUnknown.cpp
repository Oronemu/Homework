#include "IUnknown.h"

U_LONG IClassFactory::AddRef() {
    countReference++;
    return countReference;
}

U_LONG IClassFactory::Release() {
    countReference--;
    if(countReference == 0) {
        delete this;
    }
    return countReference;
}