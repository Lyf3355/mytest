#include<func.h>

int main(int argc,char* argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd=open(argv[1],O_RDWR);
	ERROR_CHECK(fd,-1,"open");
	char *c;
	c=(char*)mmap(NULL,5,PROT_WRITE,MAP_SHARED,fd,0);
	//ERROR_CHECK(c,-1,"mmap");
	strcpy(c,"world");
	munmap(c,5);
	return 0;
}
