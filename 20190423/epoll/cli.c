#include<func.h>

int main(int argc,char* argv[])
{
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	ERROR_CHECK(sfd,-1,"socket");
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(ser));
	ERROR_CHECK(ret,-1,"connect");
	printf("success connect\n");
	printf("%s %d\n",inet_ntoa(ser.sin_addr),ntohs(ser.sin_port));
	fd_set rdset;
	char buf[128]={0};
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO,&rdset);
		FD_SET(sfd,&rdset);
		ret=select(sfd+1,&rdset,NULL,NULL,NULL);
		ERROR_CHECK(ret,-1,"select");
		if(FD_ISSET(sfd,&rdset))
		{
			bzero(buf,sizeof(buf));
			ret=recv(sfd,buf,sizeof(buf),0);
			ERROR_CHECK(ret,-1,"recv");
			if(0==ret)
			{
				break;	
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
			ret=send(sfd,buf,strlen(buf)-1,0);
			ERROR_CHECK(ret,-1,"send");
		}
	}
		close(sfd);
		return 0;
}
