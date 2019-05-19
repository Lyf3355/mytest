#include "function.h"

int transfile(int newfd)
{
    int ret;
	train tra;
	tra.len=strlen(FILENAME);
	strcpy(tra.buf,FILENAME);
	ret=send(newfd,&tra,4+tra.len,0);
	int fd=open(FILENAME,O_RDONLY);
	ERROR_CHECK(fd,-1,"open");
	struct stat buf;
    fstat(fd,&buf);
    tra.len=sizeof(buf.st_size);
    memcpy(tra.buf,&buf.st_size,tra.len);
    ret=send(newfd,&tra,4+tra.len,0);
    ERROR_CHECK(ret,-1,"send");
    while((tra.len=read(fd,tra.buf,sizeof(tra.buf))))//read每次返回读到的字符数
	{
		send(newfd,&tra,4+tra.len,0);
        ERROR_CHECK(ret,-1,"send");
	}
	send(newfd,&tra,4,0);
	return 0;
}
