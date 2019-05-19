#include<func.h>
void change(int fd)
{
	int status=fcntl(fd,F_GETFL);
	status=status|O_NONBLOCK;
	fcntl(fd,F_SETFL,status);
}

int main(int argc,char* argv[])
{
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	ERROR_CHECK(sfd,-1,"socket");
	struct sockaddr_in sockaddr;
	bzero(&sockaddr,sizeof(sockaddr));
	sockaddr.sin_family=AF_INET;
	sockaddr.sin_port=htons(atoi(argv[2]));
	sockaddr.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=bind(sfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
	ERROR_CHECK(ret,-1,"bind");
	ret=listen(sfd,10);
	ERROR_CHECK(ret,-1,"listen");
	struct sockaddr_in clientadd;
	bzero(&clientadd,sizeof(clientadd));
	int newfd;
	int addrlen=sizeof(clientadd);
	newfd=accept(sfd,(struct sockaddr*)&clientadd,&addrlen);
	ERROR_CHECK(newfd,-1,"accept");
	char buf[128]={0};
	int epfd=epoll_create(1);
	ERROR_CHECK(epfd,-1,"epoll_create");
	struct epoll_event event,evs[2];
	event.events=EPOLLIN;
	event.data.fd=STDIN_FILENO;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
	ERROR_CHECK(ret,-1,"epoll_ctl");
	event.events=EPOLLIN|EPOLLIN;
	change(newfd);
	event.data.fd=newfd;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
	int readNum;
	while(1)
	{
		memset(evs,0,sizeof(evs));
		readNum=epoll_wait(epfd,evs,2,-1);
		for(int i=0;i<readNum;i++)
		{
			if(evs[i].data.fd==newfd)
			{
				while(1)
				{
					bzero(buf,sizeof(buf));
					ret= recv(newfd,buf,sizeof(buf)-1,0);
					if(0==ret)
					{
						goto over;
					}else if(-1==ret)
					{
						break;
					}else{
						printf("%s",buf);
					}
				}
			}
			if(evs[i].data.fd==0)
			{
				bzero(buf,sizeof(buf));
				ret=read(STDIN_FILENO,buf,sizeof(buf));
				ERROR_CHECK(ret,-1,"read");
				if(0==ret)
				{
					goto over;
				}
				ret=send(newfd,buf,strlen(buf)-1,0);
				ERROR_CHECK(ret,-1,"send");
			}
		}
	}
over:
	close(newfd);	
	close(sfd);
	return 0;
}
