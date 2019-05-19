#include<func.h>                                 
int main()
{    
	int semid=semget(1002,2,IPC_CREAT|0600);
	unsigned short arr[2]={10,0};
	semctl(semid,0,SETALL,arr);
	struct sembuf sopp,sopv;
	if(!fork())
	{
		sopp.sem_num=0;
		sopp.sem_op=-1;
		sopp.sem_flg=SEM_UNDO;
		sopv.sem_num=1;
		sopv.sem_op=1;
		sopv.sem_flg=SEM_UNDO;
		while(1)
		{
			printf("i am producer,produtor=%d,space=%d\n",semctl(semid,1,GETVAL),semctl(semid,0,GETVAL));
			semop(semid,&sopp,1);
			printf("i am producing\n");
			semop(semid,&sopv,1);
			printf("i am producer,produtor=%d,space=%d\n",semctl(semid,1,GETVAL),semctl(semid,0,GETVAL));
			sleep(1);
		}
	}else
	{
		sopp.sem_num=1;
		sopp.sem_op=-1;
		sopp.sem_flg=SEM_UNDO;
		sopv.sem_num=0;
		sopv.sem_op=1;
		sopv.sem_flg=SEM_UNDO;
		while(1)
		{
			printf("i am customer,productor=%d,space=%d\n",semctl(semid,1,GETVAL),semctl(semid,0,GETVAL));
			semop(semid,&sopp,1);
			printf("i am consuming\n");
			semop(semid,&sopv,1);
			printf("i am customer,productor=%d,space=%d\n",semctl(semid,1,GETVAL),semctl(semid,0,GETVAL));
			sleep(3);
		}
	}
	return 0;
}   
