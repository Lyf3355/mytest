#include<func.h>

int tcpInit(int *psfd,char* ip,char* port)
{
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	ERROR_CHECK(sfd,-1,"socket");
	struct sockaddr_in sockaddr;
	bzero(&sockaddr,sizeof(sockaddr));
	sockaddr.sin_family=AF_INET;
	sockaddr.sin_port=htons(atoi(port));
	sockaddr.sin_addr.s_addr=inet_addr(ip);
	int ret;
	ret=bind(sfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
	ERROR_CHECK(ret,-1,"bind");
	ret=listen(sfd,10);
	ERROR_CHECK(ret,-1,"listen");
	*psfd=sfd;
	return 0;
}
