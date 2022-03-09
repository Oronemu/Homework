class IUnknown {
    public:
        virtual int QueryInterface(int iid, void** ppv) = 0;
};