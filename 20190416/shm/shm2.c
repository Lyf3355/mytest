#include<func.h>

int main()
{
	int shmid;
	shmid=shmget(1000,4096,IPC_CREAT|0600);
	ERROR_CHECK(shmid,-1,"shmget");
	char *p=(char*)shmat(shmid,NULL,0);
	printf("%s\n",p);
	shmctl(shmid,IPC_RMID,0);
	return 0;
}
