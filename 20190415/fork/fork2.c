#include<func.h>

int main()
{
	pid_t iret=fork();
	int num=12;
	if(iret==0)
	{
		printf("i am child\n");
		printf("child pid:%d\n",getpid());
		printf("num=%d\n",num);
	}
	else{
		num =6;
		printf("i am parent\n");
		printf("parent pid:%d\n",getpid());
		printf("num=%d\n",num);
		sleep(1);
	}
	return 0;
}


