#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

#define MYPRINTF printf("in %s at %d:",__FILE__,__LINE__);printf
#define PIPE_NAME "/tmp/myfifo"

int main(int argc,char* argv[])
{
    int wfd = -1;
    int ret = -1;
    char buf[64] = "";

    if(access(PIPE_NAME,F_OK))
    {
        ret = mkfifo(PIPE_NAME,0666);
        if(ret < 0)
        {
            MYPRINTF("mkfifo failed\n");
            return 1;
        }
    }

    wfd = open(PIPE_NAME,O_WRONLY);

    fgets(buf,64,stdin);
    write(wfd,buf,64);

    return 0;
}