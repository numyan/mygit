#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MYPRINTF printf("in %s at %d:",__FILE__,__LINE__);printf
#define PIPE_NAME "/tmp/myfifo"

int main(int argc,char* argv[])
{
    int rfd = -1;
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

    rfd = open(PIPE_NAME,O_RDONLY);

    read(rfd,buf,64);
    write(1,buf,64);

    return 0;
}