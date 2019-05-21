#include <stdio.h>
#include <string.h>

struct Info
{
	char name[20];
	int age;
	float weight;
};

#define N 4
int main(int argc,char *argv[])
{
	struct Info arr[N] = {{""}};
	char buf[32] = "";
	FILE *pf = NULL;
	char *p = NULL;
	int i = 0;
	char *q = NULL;
	
	pf = fopen("stu.txt","r");
	if(NULL == pf)
	{
		printf("fopen failed\n");
		return 1;
	}
	
	p = fgets(buf,32,pf);
	while(p != NULL && i < N)
	{
		/*q指向buf首地址*/
		q = buf;
		
		/*在字符串中找'#'*/
		q = strstr(buf,"#");
		
		/*copy人名*/
		strncpy(arr[i].name,buf,q - buf);

		/*q指向年龄第一个字符*/
		q++;

		/*取得年龄*/
		sscanf(q,"%d",&arr[i].age);

		/*从q的当前位置开始在字符串中继续找'#'*/
		q = strstr(q,"#");
	
		/*q指向体重第一个字符*/
		q++;

		/*取得体重*/
		sscanf(q,"%f",&arr[i].weight);

		/*为下次循环做准备*/
		memset(buf,0,32);
		i++;
		p = fgets(buf,32,pf);
	}
	
	fclose(pf);
	pf = NULL;

	for(i = 0;i < N;i++)
	{
		printf("Name:%s,age:%d,weight:%.2f\n",
				arr[i].name,
				arr[i].age,
				arr[i].weight);
	}	
	return 0;
}




