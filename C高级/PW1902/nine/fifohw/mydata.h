#ifndef MY_DATA_H
#define MY_DATA_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct MyData
{
	int count;
	char buf[1];
};

#define FIFO_NAME   "/tmp/mydatafifo"

#define MYPrintf  printf("In %s at %d:",__FILE__,__LINE__);printf


#endif
