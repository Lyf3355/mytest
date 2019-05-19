#include<func.h>
#define N 10000000 
int main()
{
	int shmid;
	shmid=shmget(1002,4096,0600|IPC_CREAT);
	int *p;
	p=(int*)shmat(shmid,NULL,0);
	p[0]=0;
	int semid=semget(1000,1,IPC_CREAT|0600);
	semctl(semid,0,SETVAL,1);
	struct sembuf sopsl;
	struct sembuf sopso;
	sopsl.sem_num=0;
	sopsl.sem_op=-1;
	sopsl.sem_flg=SEM_UNDO;
	sopso.sem_num=0;
	sopso.sem_op=1;
	sopso.sem_flg=SEM_UNDO;
	int i;
	if(!fork())
	{
		for(i=0;i<N;i++)
		{
			semop(semid,&sopsl,1);
			p[0]=p[0]+1;
			semop(semid,&sopso,1);
		}
		return 0;
	}else
	{
		for(i=0;i<N;i++)
		{
			semop(semid,&sopsl,1);
			p[0]=p[0]+1;
			semop(semid,&sopso,1);
		}wait(NULL);
	}
	printf("%d\n",p[0]);
	shmctl(shmid,IPC_RMID,0);
	semctl(semid,IPC_RMID,0);
	return 0;

}
