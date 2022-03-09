#include "IUnknown.h"

class IServer: public IUnknown {
    public:
        virtual void Func() = 0;
};

class IServer2: public IUnknown {
    public:
        virtual void Func2() = 0;
};