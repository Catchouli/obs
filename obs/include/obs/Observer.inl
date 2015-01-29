#include "obs/Observer.h"
#include "obs/Connection.h"

namespace obs
{
    Observer::~Observer()
    {
        // Disconnect all connections
        for (auto& connection : mConnections)
        {
            connection->disconnect();
        }
    }
}