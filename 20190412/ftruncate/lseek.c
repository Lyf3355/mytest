#include<func.h>

int main(int argc,char* argv[])
{
	int fd;
	fd=open(argv[1],2);
	lseek(fd,1024,SEEK_SET);
	write(fd,"a",1);
	close(fd);
	return 0;
}
