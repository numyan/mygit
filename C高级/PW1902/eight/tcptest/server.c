#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	int servfd = -1;
	struct sockaddr_in servaddr;
	int ret = 0;
	int datafd = -1;
	char buf[8] = "";

	servfd = socket(AF_INET,SOCK_STREAM,0);	
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(2345);
	inet_aton("127.0.0.1",&servaddr.sin_addr);

	ret = bind(servfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	ret += listen(servfd,5);
	/*
		变主动套接字(插头)为被动套接字（插排）
		该函数并不负责客户端的连接请求,可以认为系统的TCP协议在处理连接请求，因此listen并不阻塞等待连接请求
	*/
	if(ret < 0)
	{
		printf("bind or listen failed in %s at %d\n",__FILE__,__LINE__);
	}

	while(1)
	{
		datafd = accept(servfd,NULL,NULL);
		/*
			如果有客户端发起连接被系统处理成功则accept返回
			否则该函数阻塞等待是否有连接处理成功
			其返回的是用来与已经连接成功的对应客户端交互数据用的套接字(插孔)
		*/
		read(datafd,buf,8);
		printf("In server buf=%s\n",buf);
		write(datafd,"Hello",6);
		close(datafd);
	}

	close(servfd);
	servfd = -1;
	return 0;
}
