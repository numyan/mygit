#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	int sockfd = -1;
	struct sockaddr_in servaddr;
	char buf[8] = "";

	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(7788);
	inet_aton("127.0.0.1",&servaddr.sin_addr);

	sendto(sockfd,"Hello",6,0,(struct sockaddr *)&servaddr,sizeof(servaddr));
	recvfrom(sockfd,buf,6,0,NULL,NULL);
	printf("Client buf=%s\n",buf);

	close(sockfd);
	sockfd = -1;
	return 0;
}
