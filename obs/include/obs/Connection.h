#pragma once

namespace obs
{
    template <typename... Args>
    class Signal;

    /** The base class for connections */
    class ConnectionBase
    {
    public:

        virtual void disconnect() = 0;

    };

    /** The base class for connections with specific arguments */
    template <typename... Args>
    class Connection
        : public ConnectionBase
    {
    public:

        virtual void emit(Args... args) = 0;

        virtual void disconnect() override = 0;

    };

    /** A connection to a member function */
    template <typename T, typename... Args>
    class Connection_MemberFunctionPointer
        : public Connection<Args...>
    {
    public:

        typedef void (T::*PointerType)(Args...);

        Connection_MemberFunctionPointer(T* objectPtr, PointerType functionPtr, Signal<Args...>* signal);

        void emit(Args... args) override;

        void disconnect() override;

    private:

        T* mObjectPtr;
        PointerType mFunctionPtr;
        Signal<Args...>* mSignal;

    };

}

#include "obs/Connection.inl"