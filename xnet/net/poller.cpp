#include "poller.h"

#include "xnet/net/event_handler.h"

namespace XNet
{
    
Poller::Poller(EventLoop* loop)
  : ownerLoop_(loop)
{
}

Poller::~Poller() = default;

bool Poller::hasHandler(EventHandler* handler) const
{
  EventHandlerMap::const_iterator it = m_eventMap.find(handler->fd());
  return it != m_eventMap.end() && it->second == handler;
}

}






