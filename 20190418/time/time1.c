#include<func.h>

void sigtime(int signum)
{
	time_t now;
	now=time(NULL);
	printf("%s\n",ctime(&now));
}

int main()
{
	signal(SIGALRM,sigtime);
	struct itimerval t;
	bzero(&t,sizeof(t));
	t.it_value.tv_sec=3;
	t.it_interval.tv_sec=2;
	setitimer(ITIMER_REAL,&t,NULL);
	sleep(5);
	while(1);
}
