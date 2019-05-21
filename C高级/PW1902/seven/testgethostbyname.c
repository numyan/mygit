#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include <stdio.h>

int main(int argc,char *argv[])
{
	struct hostent *pst = NULL;
	char **ppaliases = NULL;
	struct in_addr **ppIpInt = NULL;

	if(argc < 2)
	{
		printf("argument too few in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	pst = gethostbyname(argv[1]);
	printf("h_name:%s\n",pst->h_name);

	ppaliases = pst->h_aliases;
	while(*ppaliases != NULL)
	{
		printf("aliases:%s\n",*ppaliases);
		ppaliases++;
	}

	ppIpInt = (struct in_addr **)pst->h_addr_list;
	while(*ppIpInt != NULL)
	{
		printf("IntIP:0x%x\n",(unsigned int)((*ppIpInt)->s_addr));
		printf("IP String:%s\n",inet_ntoa(**ppIpInt));
		ppIpInt++;
	}
	
	/*
		**(struct in_addr **)pst->h_addr_list
	*/	
	return 0;
}
