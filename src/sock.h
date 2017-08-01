#ifndef SOCK_H
#define SOCK_H

#define HOST_TCP_PORT	1313
#define MAX_CLIENT_NUM	3

int socketServer(unsigned short port);
int handleServer(int fd);


#endif