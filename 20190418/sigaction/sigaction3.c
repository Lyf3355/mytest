#include<func.h>

void handle(int signum,siginfo_t *p,void *p1)
{
	printf("before %d is coming\n",signum);
	sleep(2);
	sigset_t pending;
	sigpending(&pending);
	if(sigismember(&pending,SIGQUIT))
	{
		printf("SIGQUIT is pending\n");
	}else{
		printf("SIGQUIT not is pengding\n");
	}
	printf("after %d is coming\n",signum);
}

int main()
{
	struct sigaction sig;
	bzero(&sig,sizeof(sig));
	sig.sa_flags=SA_SIGINFO;
	sig.sa_sigaction=handle;
	sigaddset(&sig.sa_mask,SIGQUIT);
	sigaction(SIGINT,&sig,NULL);
	sigaction(SIGQUIT,&sig,NULL);
	while(1);
}

