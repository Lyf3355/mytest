#include<func.h>

typedef struct{
	long mtype;
	char mtext[4096];
}date;

int main()
{
	int msgid;
	msgid=msgget(1000,IPC_CREAT|0600);
	date rsv;
//	char buf[128];
	//msgrcv(msgid,&rsv,sizeof(rsv.mtext),0,0);
	system("reset");
	while(1)
	{
		msgrcv(msgid,&rsv,sizeof(rsv.mtext),0,0);
		//strcpy(buf,rsv.mtext);
		if(rsv.mtype==1)
		{
			//msgrcv(msgid,&rsv,sizeof(rsv.mtext),1,0);
			printf("%s\n",rsv.mtext);

			bzero(rsv.mtext,sizeof(rsv.mtext));
		//	rsv.mtype=0;
		}else if(rsv.mtype==2)
		{
			//msgrcv(msgid,&rsv,sizeof(rsv.mtext),2,0);
			printf("%60s",rsv.mtext);
			bzero(rsv.mtext,sizeof(rsv.mtext));
		//	rsv.mtype=0;
		}else if(rsv.mtype==3)
		{
			printf("%s",rsv.mtext);
			msgctl(msgid,IPC_RMID,NULL);
			break;
		}
	}
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}








