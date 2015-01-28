#pragma once

#include "obs/Connection.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>

namespace obs
{
    class Observer;

    template <typename... Args>
    class Signal
    {
    public:

        typedef Connection<Args...> ConnectionType;

        template <typename T>
        void connect(T* objectPtr, typename Connection_MemberFunctionPointer<T, Args...>::PointerType fp)
        {
            auto ptr = std::make_shared<Connection_MemberFunctionPointer<T, Args...>>(objectPtr, fp);

            mObservers[objectPtr].push_back(ptr);
        }

        template <typename T>
        void disconnect(T* objectPtr)
        {
            mObservers.erase(objectPtr);
        }

        void emit(Args... args)
        {
            for (auto& observer : mObservers)
            {
                for (auto& connection : observer.second)
                {
                    connection->emit(args...);
                }
            }
        }

        std::unordered_map<Observer*, std::vector<std::shared_ptr<ConnectionType>>> mObservers;

    };

}