#include "function.h"

int makeChild(processData * p,int num)
{
	int fds[2];
	pid_t pid;
	for(int i=0;i<num;i++)
	{
		socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		pid=fork();
		if(0==pid)
		{
			close(fds[1]);
			childHandle(fds[0]);
		}
		close(fds[0]);
		p[i].pid=pid;
		p[i].fd=fds[1];
		p[i].busy=0;
	}
	return 0;
}

int childHandle(int fd)
{
	int newfd;
	while(1)
	{
		recvFd(fd,&newfd);
		transfile(newfd);
		close(newfd);
		write(fd,&newfd,1);
	}
}

