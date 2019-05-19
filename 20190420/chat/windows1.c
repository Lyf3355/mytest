#include<func.h>

typedef struct{
	int flat;
	char buf[4096];
}date;

int main()
{
	int shmid;
	//int pid;
	//pid=getpid();
	shmid=shmget(1000,4096,IPC_CREAT|0600);
	date* p=(date*)shmat(shmid,NULL,0);
	system("reset");
	while(1){
		if(p->flat==1)
		{
			printf("%s\n",p->buf);
		}
		else if(p->flat==2)
		{
			printf("%60s",p->buf);
		}
		else if(p->flat==3)
		{
			printf("%s\n",p->buf);
			shmctl(shmid,IPC_RMID,NULL);
			 kill(getpid(),SIGQUIT);
			break;
		}
		memset(p,0,4096);
	}
	shmdt(p);
}
