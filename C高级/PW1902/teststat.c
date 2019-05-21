/*系统调用头文件*/
/*C库头文件*/
/*第三方头文件*/
/*其它模块提供的头文件*/
/*本模块对外提供的头文件*/
/*本模块私有头文件*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	struct stat st;

	if(argc < 2)
	{
		printf("argument too few in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	
	if(stat(argv[1],&st))
	{
		printf("call stat failed in %s at %d\n",__FILE__,__LINE__);
		return 2;
	}

	printf("size of %s is %d\n",argv[1],(int)st.st_size);

	switch (st.st_mode & S_IFMT)
	{
    	case S_IFBLK:  
			printf("block device\n");
            break;
        case S_IFCHR:
			printf("character device\n");
	        break;
        case S_IFDIR:
			printf("directory\n");
			break;
        case S_IFIFO:
			printf("FIFO/pipe\n");
			break;
        case S_IFLNK:
			printf("symlink\n");
            break;
        case S_IFREG:
			printf("regular file\n");
            break;
        case S_IFSOCK:
			printf("socket\n");
			break;
        default:
			printf("unknown?\n");         
			break;
	}

	return 0;
}
