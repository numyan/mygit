#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//
char* my_ntoa(unsigned int intip);
//
unsigned int my_aton(char* strip);

char* my_ntoa(unsigned int intip)
{
    static char ipstr[16] = "";
    memset(ipstr,0,sizeof(ipstr));
    int i = 0;
    int ipPart = 0;
    char tmp[4] = "";

    for(i = 0;i < 4;i++)
    {
        memset(tmp,0,sizeof(tmp));
        ipPart = intip % (int)pow(16,2);
        intip = intip / pow(16,2);
        sprintf(tmp,"%d",ipPart);    
        strcat(ipstr,".");
        strcat(ipstr,tmp);
    }

   return ipstr+1; 
}

unsigned int my_aton(char* strip)
{
    int i = 0;
    int ipInt = 0;//返回的整数ip
    char* buf = NULL;
    char ipPart[4] = "";
    int tmp = 0;

    buf = strip;
    for(i = 0;i < 3;i++)
    {
        memset(ipPart,0,sizeof(ipPart));
        buf = strstr(strip,".");
        strncpy(ipPart,strip,buf-strip);//
        sscanf(ipPart,"%d",&tmp);

        memset(ipPart,0,sizeof(ipPart));

        ipInt = tmp*pow(16,2*i) + ipInt;

        buf = buf+1;
        strip = buf; 
    }
    sscanf(strip,"%d",&tmp);
    ipInt = tmp*pow(16,6) + ipInt;
    return ipInt;
}

int main(int argc,char* argv[])
{
    struct hostent *pst = NULL;
    char** ppaliases = NULL;
    struct in_addr **ppIpInt = NULL;

    if(argc < 2)
    {
        printf("augument too few in %s at %d\n",__FILE__,__LINE__);
        return 1;
    }

    pst = gethostbyname(argv[1]);
    printf("hostname:%s\n",pst->h_name);

    ppaliases = pst->h_aliases;
    while(NULL != *ppaliases)
    {
        printf("aliases:%s\n",*ppaliases);
        ppaliases++;
    }

    ppIpInt = (struct in_addr**)pst->h_addr_list;
    while(NULL != *ppIpInt)
    {
        printf("IP STRING:%s\n",my_ntoa((unsigned int)((*ppIpInt)->s_addr)));
        printf("IntIp:0x%x\n",my_aton(my_ntoa((unsigned int)((*ppIpInt)->s_addr))));
        ppIpInt++;
    }
;
    return 0;
}