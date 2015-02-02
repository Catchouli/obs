#include "obs/Observer.h"
#include "obs/Connection.h"

namespace obs
{
    Observer::~Observer()
    {
        // Copy list so it can be modified
        auto connections = mConnections;

        // Disconnect all connections
        for (auto& connection : connections)
        {
            connection->disconnect();
        }
    }
}