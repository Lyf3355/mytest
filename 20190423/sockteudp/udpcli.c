#include<func.h>

int main(int argc,char* argv[])
{
	ARGS_CHECK(argc,3);
	int sockdFD;
	sockdFD=socket(AF_INET,SOCK_DGRAM,0);
	ERROR_CHECK(sockdFD,-1,"socket");
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=sendto(sockdFD,"i",1,0,(struct sockaddr*)&ser,sizeof(ser));
	ERROR_CHECK(ret,-1,"sendto");
	char buf[128];
	fd_set rdset;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(STDIN_FILENO,&rdset);
		FD_SET(sockdFD,&rdset);
		ret=select(sockdFD+1,&rdset,NULL,NULL,NULL);
		if(FD_ISSET(sockdFD,&rdset))
		{
			bzero(buf,sizeof(buf));
			ret=recvfrom(sockdFD,buf,sizeof(buf),0,NULL,NULL);
			ERROR_CHECK(ret,-1,"recvfrom");
			printf("%s\n",buf);

		}
		if(FD_ISSET(STDIN_FILENO,&rdset))
		{
			bzero(buf,sizeof(buf));
			ret=read(STDIN_FILENO,buf,sizeof(buf));
			if(ret==0)
			{
				break;
			}
			ret=sendto(sockdFD,buf,strlen(buf)-1,0,(struct sockaddr*)&ser,sizeof(ser));
			ERROR_CHECK(ret,-1,"sendto");
		}
	}
		close(sockdFD);
}

