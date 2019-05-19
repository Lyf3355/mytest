#include<errno.h>
#include<sys/epoll.h>
#include<arpa/inet.h> 
#include<netinet/in.h> 
#include<netdb.h>
#include<sys/socket.h>
#include<sys/msg.h>
#include<pthread.h>
#include<time.h>
#include<sys/time.h>
#include<signal.h>
#include<sys/sem.h>
#include <sys/shm.h>
#include<sys/ipc.h>
#include<sys/ipc.h>
#include <sys/wait.h>
#include<ctype.h>
#include<sys/time.h>
#include<signal.h>
#include<pwd.h>
#include<grp.h>
#include<sys/select.h>
#include<stdio.h>
#include<errno.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>

#define ARGS_CHECK(argc,val){if(argc!=val)\
	{printf("error args\n");return -1;}}
#define ERROR_CHECK(ret,retval,funcName){if(ret==retval)\
	{perror(funcName);return -1;}}

int recvCycle(int newfd,void *p,int len);
