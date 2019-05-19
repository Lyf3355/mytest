#include <func.h>

int main(int argc,char* argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd=open(argv[1],O_WRONLY);
	ERROR_CHECK(fd,-1,"open");
	printf("write fd=%d\n",fd);
	sleep(3);
	write(fd,"hello",5);
	return 0;
}

