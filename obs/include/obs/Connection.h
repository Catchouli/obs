#pragma once

namespace obs
{

    template <typename... Args>
    class Connection
    {
    public:

        virtual void emit(Args... args) = 0;

    };

    template <typename T, typename... Args>
    class Connection_MemberFunctionPointer
        : public Connection<Args...>
    {
    public:

        typedef void (T::*PointerType)(Args...);

        Connection_MemberFunctionPointer(T* objectPtr, PointerType functionPtr)
            : mObjectPtr(objectPtr), mFunctionPtr(functionPtr)
        {
        }

        void emit(Args... args) override
        {
            (mObjectPtr->*mFunctionPtr)(args...);
        }

        T* mObjectPtr;
        PointerType mFunctionPtr;

    };

}