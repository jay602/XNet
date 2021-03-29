#ifndef _XNET_EVENT_HANDLER_H_
#define _XNET_EVENT_HANDLER_H_

#include <functional>

namespace XNet
{

class EventLoop;

const int kNoneEvent = 0;
const int kReadEvent = 1;
const int kWriteEvent = 2;

class EventHandler
{
public:
    typedef std::function<void()> EventCallBack;

    EventHandler(EventLoop* loop, int fd);
    ~EventHandler();

    void handleEvent();

    void setReadCallBack(EventCallBack cb) { m_readCallBack = cb;}
    void setWriteCallBack(EventCallBack cb) { m_writeCallBack = cb;}
    void setErrorCallBack(EventCallBack cb) { m_errorCallBack = cb;}

private:
    EventCallBack m_readCallBack;
    EventCallBack m_writeCallBack;
    EventCallBack m_errorCallBack;

    int m_fd;
};




} // namespace XNet


#endif