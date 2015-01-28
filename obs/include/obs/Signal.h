#pragma once

#include "obs/Connection.h"

namespace obs
{

    template <typename... Args>
    class Signal
    {
    public:

        typedef Connection<Args...> ConnectionType;

        template <typename T>
        void connect(T* objectPtr, typename Connection_MemberFunctionPointer<T, Args...>::PointerType fp)
        {
            mConnections.push_back(std::make_shared<Connection_MemberFunctionPointer<T, Args...>>(objectPtr, fp));
        }

        void emit(Args... args)
        {
            for (auto& connection : mConnections)
            {
                connection->emit(args...);
            }
        }

        std::vector<std::shared_ptr<ConnectionType>> mConnections;

    };

}