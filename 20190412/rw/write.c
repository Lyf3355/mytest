#include<func.h>

int main(int argc,char* argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd=open(argv[1],O_RDWR);
	ERROR_CHECK(fd,-1,"open");
	int arr[5]={5,4,3,2,1};
	int ret;
	ret=write(fd,arr,sizeof(arr));
	ERROR_CHECK(fd,-1,"write");
	return 0;
}
