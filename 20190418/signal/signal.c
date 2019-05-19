#include<func.h>

void handler(int signum)
{
	printf("%dbefor\n",signum);
	sleep(2);
	printf("%dafter\n",signum);
}
int main()
{	
	signal(SIGINT,handler);
	signal(SIGQUIT,handler);
	while(1);
}
