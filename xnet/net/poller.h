#ifndef _POLLER_H_
#define _POLLER_H_

#include "xnet/base/noncopyable.h"
#include <vector>

namespace XNet
{

class EventHandler;
class EventLoop;

class Poller : noncopyable
{
public:
    typedef std::vector<EventHandler* > EventHandlerList;
    
    Poller(EventLoop* loop);
    ~Poller();

    virtual void poll(int timeoutMs, EventHandlerList* handlerList) = 0;

    virtual void updateChannel(Channel* channel) = 0;

    virtual void removeChannel(Channel* channel) = 0;

protected:
    typedef std::map<int, EventHandler*> EventHandlerMap;
    EventHandlerMap m_eventMap;

private:
    EventLoop* m_loop;
};

}

#endif