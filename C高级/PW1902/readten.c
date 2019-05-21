#include <stdio.h>

int main(int argc,char *argv[])
{
	FILE *pf = NULL;
	char ch = '\0';

	pf = fopen("c.txt","r");
	if(NULL == pf)
	{
		printf("fopen failed %s, in %s at %d\n","c.txt",__FILE__,__LINE__);
		return 1;
	}
	fseek(pf,9,SEEK_SET);
	ch = fgetc(pf);
	fclose(pf);
	pf = NULL;

	printf("This char is %c\n",ch);
	return 0;
}
