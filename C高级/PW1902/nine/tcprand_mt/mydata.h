#ifndef MY_DATA_H
#define MY_DATA_H

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct MyData
{
	int count;
	char buf[1];
};

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6789

#define ClientPrintf  printf("Client in %s at %d:",__FILE__,__LINE__);printf
#define ServerPrintf  printf("Server in %s at %d:",__FILE__,__LINE__);printf

#endif
