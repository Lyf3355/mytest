#include<func.h>

int main()
{
	pid_t iret=fork();
	if(iret==0)
	{
		printf("i am child\n");
		printf("child pid:%d\n",getpid());
		while(1);
	}
	else{
		printf("i am parent\n");
		printf("parent pid:%d\n",getpid());
		while(1);
	}
	return 0;
}


