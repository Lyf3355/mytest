#include<func.h>

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
	//newfd=accept(sfd,(struct sockaddr*)&clientadd,&addrlen);
	//ERROR_CHECK(newfd,-1,"accept");
	fd_set rdset;
	fd_set monitor;
	FD_ZERO(&monitor);
	FD_SET(STDIN_FILENO,&monitor);
	FD_SET(sfd,&monitor);
	char buf[128]={0};
	while(1)
	{
		memcpy(&rdset,&monitor,sizeof(fd_set));
		ret=select(11,&rdset,NULL,NULL,NULL);
		ERROR_CHECK(ret,-1,"select");
		if(FD_ISSET(sfd,&rdset))
		{
			newfd=accept(sfd,(struct sockaddr*)&clientadd,&addrlen);
			ERROR_CHECK(newfd,-1,"accept");
			printf("%s %d\n",inet_ntoa(clientadd.sin_addr),ntohs(clientadd.sin_port));
			FD_SET(newfd,&monitor);
		}
		if(FD_ISSET(newfd,&rdset))
		{
			bzero(buf,sizeof(buf));
			ret=recv(newfd,buf,sizeof(buf),0);
			ERROR_CHECK(ret,-1,"recv");
			if(0==ret)
			{
				FD_CLR(newfd,&monitor);
				close(newfd);
				continue;
			}
			puts(buf);
		}
		if(FD_ISSET(STDIN_FILENO,&rdset))
		{
			bzero(buf,sizeof(buf));
			read(STDIN_FILENO,buf,sizeof(buf));
			if(0==ret)
			{
				break;
			}
			ret=send(newfd,buf,strlen(buf)-1,0);
		}
	}
		close(sfd);
	return 0;
}
