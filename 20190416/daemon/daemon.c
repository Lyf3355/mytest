#include<func.h>

void Daemon()
{
	pid_t pid=fork();
	if(pid)
	{
		exit(0);
	}
	setsid();
	chdir("/");
	umask(0);
	for(int i=0;i<3;i++)
		close(i);
}
int main()
{
	int fd=open("/tmp/log",O_RDWR|O_CREAT,0600);
	char buf[128]="i have run 5s";
	Daemon();
	while(1)
	{

		sleep(5);
		write(fd,buf,sizeof(buf));
	}
	return 0;
}
