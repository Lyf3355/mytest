#include<func.h>

typedef struct {
	int flag;
	char buf[1024];
}date;

void handle(int signum)
{
	int shmid=shmget(1000,4096,IPC_CREAT|0600);
	date *p=(date*)shmat(shmid,NULL,0);
	p->flag=3;
	strcpy(p->buf,"会话结束\n");
}

int main(int argc,char* argv[])
{
	signal(SIGINT,handle);
	ARGS_CHECK(argc,3);
	int fdr,fdw;
	fdr=open(argv[1],O_RDONLY);
	ERROR_CHECK(fdr,-1,"open");
	fdw=open(argv[2],O_WRONLY);
	ERROR_CHECK(fdw,-1,"open");
	//printf("chat1 fdr=%d,fdw=%d\n",fdr,fdw);
	char buf[128]={0};
	fd_set rdset;
	int ret;
	int shmid;
	shmid=shmget(1000,4096,IPC_CREAT|0600);
	date *p=(date*)shmat(shmid,NULL,0);
	while(1)
	{
		FD_ZERO(&rdset);//清零
		FD_SET(STDIN_FILENO,&rdset);//增加绑定（放进去）
		FD_SET(fdr,&rdset);//（放进去）
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		ERROR_CHECK(ret,-1,"select");
		if(ret>0)
		{
			if(FD_ISSET(fdr,&rdset))//如果redset在里面
			{
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf,sizeof(buf));
				memset(p,0,4096);
				p->flag=1;
				strcpy(p->buf,buf);
				if(0==ret)
				{
					//memset(p,0,4096);
					//p->flag=3;
					//strcpy(p->buf,"会话结束\n");
					printf("已断开连接\n");
					break;
				}
				//puts(buf);
			}
			if(FD_ISSET(0,&rdset))//如果redset在标准输入里面（0，标准输入）
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(0==ret)
				{
					//memset(p,0,4096);
					//p->flag=3;
					//strcpy(p->buf,"会话结束\n");
					printf("结束会话\n");
					break;
				}
				write(fdw,buf,strlen(buf)-1);
				memset(p,0,4096);
				p->flag=2;
				strcpy(p->buf,buf);
			}
		}
	}
	close(fdr);
	close(fdw);
	return 0;
}
