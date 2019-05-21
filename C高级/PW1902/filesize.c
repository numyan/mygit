#include <stdio.h>

int main(int argc,char *argv[])
{
	FILE *pf = NULL;
	int size = 0;

	if(argc < 2)
	{
		printf("argument too few!!!,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}		

	pf = fopen(argv[1],"r");
	if(NULL == pf)
	{
		printf("fopen failed %s,in %s at %d\n",argv[1],__FILE__,__LINE__);
		return 2;
	}
	fseek(pf,0,SEEK_END);
	size = ftell(pf);
	fclose(pf);
	pf = NULL;
	
	printf("size of %s is %d\n",argv[1],size);
	return 0;
}







