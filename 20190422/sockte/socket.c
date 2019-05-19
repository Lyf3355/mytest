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
	newfd=accept(sfd,(struct sockaddr*)&clientadd,&addrlen);
	ERROR_CHECK(newfd,-1,"accept");
	printf("success connect\n");
	printf("%s %d\n",inet_ntoa(clientadd.sin_addr),ntohs(clientadd.sin_port));
	char buf[128]={0};
	ret=recv(newfd,buf,sizeof(buf),0);
	ERROR_CHECK(ret,-1,"recv");
	puts(buf);
	ret=send(newfd,"world",5,0);
	ERROR_CHECK(ret,-1,"send");
	close(newfd);
	close(sfd);
	return 0;
}
