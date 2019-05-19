#include "function.h"

int main(int argc,char *argv[])
{
	ARGS_CHECK(argc,4);
	int childNum=atoi(argv[3]);
	processData *pChild=(processData*)calloc(childNum,sizeof(processData));
	makeChild(pChild,childNum);
	int socketFd;
	tcpInit(&socketFd,argv[1],argv[2]);
	int epfd;
	epfd=epoll_create(1);
	struct epoll_event event,*evs;
	evs=(struct epoll_event*)calloc(childNum+1,sizeof(struct epoll_event));
	event.events=EPOLLIN;
	event.data.fd=socketFd;
	int ret;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,socketFd,&event);
	ERROR_CHECK(ret,-1,"epoll_ctl");
	for(int i=0;i<childNum;i++)
	{
		event.data.fd=pChild[i].fd;
		ret=epoll_ctl(epfd,EPOLL_CTL_ADD,pChild[i].fd,&event);
		ERROR_CHECK(ret,-1,"epoll_ctl");
	}
	int readyFdNumb;
	int newfd;
	int j;
	while(1)
	{
		readyFdNumb=epoll_wait(epfd,evs,childNum+1,-1);
		for(int i=0;i<readyFdNumb;i++)
		{
			if(evs[i].events==EPOLLIN && evs[i].data.fd==socketFd)
			{
				newfd=accept(socketFd,NULL,NULL);
				for(j=0;j<childNum;j++)
				{
					if(!pChild[j].busy)	
					{
						sendFd(pChild[j].fd,newfd);
						pChild[j].busy=1;
						printf("%d child is busy\n",pChild[j].pid);
						break;
					}
				}
				close(newfd);
			}
			for(j=0;j<childNum;j++)
			{
				if(evs[i].data.fd==pChild[j].fd)
				{
					read(pChild[j].fd,&ret,1);
					pChild[j].busy=0;
					printf("%d child is not busy\n",pChild[j].pid);	
				}	
			}
		}
	}
}
