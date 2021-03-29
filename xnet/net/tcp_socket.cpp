#include "tcp_socket.h"

#include <sys/socket.h>
#include <netinet/in.h>

TcpSocket::TcpSocket(/* args */)
{
    m_socket = socket (PF_INET, SOCK_STREAM, 0);
}

TcpSocket::~TcpSocket()
{
}

bool TcpSocket::bind(std::string ip, int port)
{
    struct sockaddr_in addr;  

    addr.sin_family = AF_INET;     
    addr.sin_port = htons(port);     
    addr.sin_addr.s_addr = inet_addr(ip.c_str()); 

    return bind(m_socket, (struct sockaddr *)&addr, sizeof(struct sockaddr));
}

int TcpSocket::listen()
{
    return listen(m_socket, 5);
}

int TcpSocket::accept()
{
    struct sockaddr_in client;
    socklen_t  addrlen;
    int ret = accept(m_socket, (struct sockaddr *)&client, &addrlen)

    if(ret == -1)
    {

    }

    return ret;
}

void TcpSocket::connect(std::string ip, int port)
{
    struct sockaddr_in server;

    bzero(&server, sizeof(server));
    server.sin_family= AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip.c_str());

    int ret = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    
    if(ret == -1)
    {
   
    }

    return ret;
}