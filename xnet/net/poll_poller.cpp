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

void PollPoller::poll()
{
    int numEvent = ::poll(&*m_pollfds.begin(), m_pollfds.size(), -1);
       
}

}