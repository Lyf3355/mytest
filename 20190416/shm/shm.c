#include<func.h>

int main()
{
	int shmid;
	shmid=shmget(1001,4096,IPC_CREAT|0600);
	ERROR_CHECK(shmid,-1,"shmget");
	char *p=(char*)shmat(shmid,NULL,0);
	memset(p,0,4096);
	strcpy(p,"How are you");
	//shmdt(p);
}
