#include <stdio.h>

int main(int argc,char *argv[])
{
	FILE * pf = NULL;
	int w = 0;
	int h = 0;

	if(argc < 2)
	{
		printf("argument too few,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	pf = fopen(argv[1],"rb");	
	if(NULL == pf)
	{
		printf("fopen failed,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	
	fseek(pf,18,SEEK_SET);
	fread(&w,sizeof(int),1,pf);
	fread(&h,sizeof(int),1,pf);

	fclose(pf);
	pf = NULL;	

	printf("Its Width is %d,Height is %d\n",w,h);
	return 0;
}









