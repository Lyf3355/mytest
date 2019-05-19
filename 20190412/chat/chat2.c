#include<func.h>

int main(int argc,char* argv[])
{
	ARGS_CHECK(argc,3);
	int fdr,fdw;
	fdw=open(argv[1],O_WRONLY);
	ERROR_CHECK(fdw,-1,"open");
	fdr=open(argv[2],O_RDONLY);
	ERROR_CHECK(fdr,-1,"open");
	printf("chat2 fdr=%d,fdw=%d\n",fdr,fdw);
	char buf[128]={0};
	fd_set rdset;
	int ret;
	while(1)
	{
		FD_ZERO(&rdset);//清零
		FD_SET(STDIN_FILENO,&rdset);//增加绑定
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		ERROR_CHECK(ret,-1,"select");
		if(ret>0)
		{
			if(FD_ISSET(fdr,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf,sizeof(buf));
				if(0==ret)
				{
					printf("已断开连接\n");
					break;
				}
				puts(buf);
			}
			if(FD_ISSET(0,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));
				if(0==ret)
				{
					printf("结束会话\n");
					break;
				}
				write(fdw,buf,strlen(buf)-1);
			}
		}
	}
	close(fdr);
	close(fdw);
	return 0;
}
