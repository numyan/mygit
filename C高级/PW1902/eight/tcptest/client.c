#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	struct sockaddr_in servaddr;
	int sockfd = -1;
	int ret = 0;
	char buf[8] = "";

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	//memset(&servaddr,0,sizeof(servaddr))
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(2345);
	inet_aton("127.0.0.1",&servaddr.sin_addr);
	
	ret = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));	if(ret < 0)
	{
		printf("connect failed in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	
	write(sockfd,"Hello",6);
	read(sockfd,buf,8);
	printf("In Client,buf=%s\n",buf);

	close(sockfd);
	sockfd = -1;
	return 0;
}
