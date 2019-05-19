#include "function.h"

int main(int argc,char* argv[])
{
	ARGS_CHECK(argc,3);
	int socketFd;
	socketFd=socket(AF_INET,SOCK_STREAM,0);
	ERROR_CHECK(socketFd,-1,"socket");
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=connect(socketFd,(struct sockaddr*)&ser,sizeof(ser));
	ERROR_CHECK(ret,-1,"connect");
	printf("connect success\n");
	int dataLen;
	char buf[1000]={0};
	recvCycle(socketFd,&dataLen,4);
	recvCycle(socketFd,buf,dataLen);
	int fd;
	fd=open(buf,O_CREAT|O_WRONLY,0666);
	ERROR_CHECK(fd,-1,"open");
	off_t filesize=0,oldsize=0,downloadsize=0,slicesize;
    recvCycle(socketFd,&dataLen,4);
    recvCycle(socketFd,&filesize,dataLen);
    slicesize=filesize/10000;
    while(1)
	{

		recvCycle(socketFd,&dataLen,4);
		if(-1==ret)
        {
            printf("server over\n");
            break;
        }
        if(dataLen>0)
		{
			recvCycle(socketFd,buf,dataLen);
		    if(-1==ret)
            {
                break;
            }
            write(fd,buf,dataLen);
            downloadsize+=dataLen;
            if(downloadsize-oldsize>slicesize)
            {
                printf("\r%5.2f%%",(float)downloadsize/filesize*100);
                fflush(stdout);
                oldsize=downloadsize;
            }
		}else{
            printf("\r100%%    \n");
			break;
		}
	}
	close(fd);
	close(socketFd);
	return 0;
}
