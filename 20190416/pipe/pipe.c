#include<func.h>

int main()
{
	int fds[2]={0};
	pipe(fds);
	char buf[128]={0};
	if(!fork())
	{
		close(fds[0]);
		write(fds[1],"hello",6);
		close(fds[1]);
		exit(0);
	}else 
	{
		close(fds[1]);
		if(read(fds[0],buf,sizeof(buf))>0)
			puts(buf);
		close(fds[0]);
		wait(NULL);
		exit(0);
	}
	return 0;
}
