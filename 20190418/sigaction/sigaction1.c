#include<func.h>

void handle(int signum,siginfo_t *p,void *p1)
{
	printf("%d is coming\n",signum);
}

int main()
{
	struct sigaction sig;
	bzero(&sig,sizeof(sig));
	sig.sa_flags=SA_SIGINFO;
	sig.sa_sigaction=handle;
	sigaction(SIGINT,&sig,NULL);
	sigaction(SIGQUIT,&sig,NULL);
	while(1);
}

