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
	printf("%s %d\n",inet_ntoa(ser.sin_addr),ntohs      (ser.sin_port));
	ret=send(sfd,"hello",5,0);
	ERROR_CHECK(ret,-1,"send");
	char buf[128]={0};
	ret=recv(sfd,buf,sizeof(buf),0);
	ERROR_CHECK(ret,-1,"recv");
	puts(buf);
	return 0;
}
