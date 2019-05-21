#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_ntoa(unsigned int ip);
unsigned int my_aton(char *ip);

int main(int argc,char *argv[])
{
	unsigned int x = 0;
	char *p = NULL;
	if(argc < 2)
	{
		printf("argument too few\n");
		return 1;
	}
	
	x = my_aton(argv[1]);
	p = my_ntoa(x);
	printf("x=0x%x\n",x);
	printf("ip=%s\n",p);

	return 0;
}

char *my_ntoa(unsigned int ip)
{
	static char buf[16] = "";
	unsigned char *p = (unsigned char *)&ip;

	sprintf(buf,"%d.%d.%d.%d",
                (int)(*p),
				(int)(*(p+1)),
				(int)(*(p+2)),
				(int)(*(p+3))
				);

	return buf;
}

unsigned int my_aton(char *ip)
{
	unsigned int ret = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	unsigned char *p = (unsigned char *)&ret;

	sscanf(ip,"%d.%d.%d.%d",&num1,&num2,&num3,&num4);
	if(num1 < 0 || num1 > 255 ||
		num2 < 0 || num2 > 255 ||
		num3 < 0 || num3 > 255 ||
		num4 < 0 || num4 > 255
		)
	{
		return 0;
	}

	*p = num1;	
	*(p+1) = num2;	
	*(p+2) = num3;	
	*(p+3) = num4;	

	return ret;
}
