#include<func.h>

int main(int argc,char* argv[])
{
	int fd;
	fd=open(argv[1],2);
	ftruncate(fd,20);
	close(fd);
	return 0;
}
