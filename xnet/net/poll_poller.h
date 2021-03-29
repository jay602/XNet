#ifndef _XNET_POLL_POLLER_H_
#define _XNET_POLL_POLLER_H_

#include "xnet/net/poller.h"

#include <vector>

namespace XNet
{
    
class PollPoller : Poller
{
public:
    PollPoller(/* args */);
    ~PollPoller();

    void poll();

private:
    typedef std::vector<struct pollfd> PollFdList;
    PollFdList m_pollfds;
};

}





#endif