#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
struct Stu
{
	char name[NAME_LEN];
	char sex;
	int age;
	float score;
};

#define N 6
#define FILE_NAME "./stu.dat"
int CmpStuByScore(const void *pv1,const void *pv2);
int main(int argc,char *argv[])
{
	int lownum = 0;
	int total = 0;
	struct Stu arrst[N] = {
							{"Zhangsan",'M',21,56.5},
							{"Lisi",'M',23,66.5},
							{"Ruhua",'F',18,43.5},
							{"Siyu",'F',19,82.5},
							{"Chunlan",'F',26,99.5},
							{"Baoqiang",'M',31,33.5}
						  };
	int i = 0;
	int fd = -1;
	struct Stu *pst = NULL;

	qsort(arrst,N,sizeof(struct Stu),CmpStuByScore);	

	for(i = 0;i < N;i++)
	{
		if(arrst[i].score < 60)
		{
			lownum++;
		}
	}

	fd = open(FILE_NAME,O_WRONLY | O_CREAT | O_TRUNC,0666);
	if(fd < 0)
	{
		printf("open %s failed in %s at %d\n",FILE_NAME,__FILE__,__LINE__);
		return 1;
	}

	total = N;
	write(fd,&total,sizeof(total));
	write(fd,&lownum,sizeof(lownum));
	for(i = 0;i < N;i++)
	{
		write(fd,&arrst[i],sizeof(struct Stu));
	}
	close(fd);
	fd = -1;

	/*读不及格学生数据*/
	fd = open(FILE_NAME,O_RDONLY);
	if(fd < 0)
	{
		printf("open %s failed in %s at %d\n",FILE_NAME,__FILE__,__LINE__);
		return 2;
	}
	
	read(fd,&total,sizeof(total));
	read(fd,&lownum,sizeof(lownum));
	
	pst = (struct Stu *)malloc(lownum * sizeof(struct Stu));
	if(NULL == pst)
	{
		printf("Malloc Failed in %s at %d\n",__FILE__,__LINE__);
		return 3;
	}
	memset(pst,0,lownum*sizeof(struct Stu));

	lseek(fd,(total-lownum)*sizeof(struct Stu),SEEK_CUR);
	for(i = 0;i < lownum;i++)
	{
		read(fd,pst+i,sizeof(struct Stu));
	}
	close(fd);
	fd = -1;

	for(i = 0;i < lownum;i++)
	{
		printf("Name:%s,Sex:%c,Age:%d,Score:%.1f\n",
				(pst+i)->name,
				(pst+i)->sex,
				(pst+i)->age,
				(pst+i)->score
				);
	}
	free(pst);
	pst = NULL;
	return 0;
}

int CmpStuByScore(const void *pv1,const void *pv2)
{
	struct Stu *pst1 = (struct Stu *)pv1;
	struct Stu *pst2 = (struct Stu *)pv2;

	if(pst1->score == pst2->score)
	{
		return 0;
	}
	else if(pst1->score > pst2->score)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
