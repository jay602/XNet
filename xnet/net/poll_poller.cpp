#include "xnet/net/poll_poller.h"

struct pollfd;

namespace XNet
{
    
PollPoller::PollPoller(/* args */)
{
}

PollPoller::~PollPoller()
{
}

void PollPoller::poll(int timeoutMs, EventHandlerList* handlerList)
{
    int numEvent = ::poll(&*m_pollfds.begin(), m_pollfds.size(), timeoutMs);
    findActiveEvent(numEvent, handlerList);
}

void PollPoller::findActiveEvent(int eventNum, EventHandlerList* handlerList)
{

}

}