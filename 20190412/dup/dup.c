#include<func.h>

int main(int argc,char*argv [])
{
	char p[128];
	int fd=open(argv[1],O_RDWR);
	read(fd,p,sizeof(p));
	printf("p=%s\n",p);
	int fd1=dup(fd);
	close(fd);
	memset(p,0,sizeof(p));
	read(fd1,p,sizeof(p));
	printf("p=%s\n",p);
	close(fd1);
	return 0;
}
	

