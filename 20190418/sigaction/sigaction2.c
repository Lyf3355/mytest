#include<func.h>

void handle(int signum,siginfo_t *p,void *p1)
{
	printf("before %d is coming\n",signum);
	sleep(2);
	printf("after %d is coming\n",signum);
}

int main()
{
	struct sigaction sig;
	bzero(&sig,sizeof(sig));
	sig.sa_flags=SA_SIGINFO|SA_NODEFER;
	sig.sa_sigaction=handle;
	sigaction(SIGINT,&sig,NULL);
	sigaction(SIGQUIT,&sig,NULL);
	while(1);
}

