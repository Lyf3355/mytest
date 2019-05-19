#include<func.h>

int main()
{
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask,SIGINT);
	sigprocmask(SIG_BLOCK,&mask,NULL);
	if(sigismember(&mask,SIGINT))
	{
		printf("SIGINT is pending\n");
	}
	sleep(5);
	sigprocmask(SIG_UNBLOCK,&mask,NULL);
	if(!sigismember(&mask,SIGINT))
	{
		printf("SIGINT not is pending\n");
	}
}
