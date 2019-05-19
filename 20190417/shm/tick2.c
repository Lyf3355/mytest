#include<func.h>                                 
int main()
{    
	int shmid;
	shmid=shmget(1002,4096,0600|IPC_CREAT);
	int *p;
	p=(int*)shmat(shmid,NULL,0);
	p[0]=20000000;
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
	int i=0;
	int j=0;
	if(!fork())
	{
		while(p[0]>0)
		{
			semop(semid,&sopsl,1);
			p[0]--;i++;
			semop(semid,&sopso,1);
		};
		while(p[0]<=0)
		{
			printf("son=%d\n",i);
			break;
		}
	}else
	{
		while(p[0]>0)
		{
			semop(semid,&sopsl,1);
			p[0]--;j++;
			semop(semid,&sopso,1);
		};
		while(p[0]<=0)
		{
			printf("parent=%d\n",j);
			break;
		}
	}
	shmctl(shmid,IPC_RMID,0);
	semctl(semid,IPC_RMID,0);
	return 0;
}   
