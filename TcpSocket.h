#ifndef TCP_SOCKET
#define TCP_SOCKET

#include <string>

class TcpSocket
{
public:
    TcpSocket(/* args */);
    ~TcpSocket();

    bool bind(std::string ip, int port);
    int listen();
    int accept();
    void connect();

private:
    int m_socket;
};

#endif