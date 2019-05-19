#include<func.h>

typedef struct student{
	char num[15];
	char name[15];
	float score;
}student;

int main(int argc,char *argv[])
{
	ARGS_CHECK(argc,2);
	student s[3]={{"001","lili",98},{"002","lele",78},{"003","huahua",88}};
	//char buf[512]={0};
	int fb=open(argv[1],O_RDWR);
	ERROR_CHECK(fb,-1,"open");
	//int ret;
	write(fb,s,sizeof(s));
	lseek(fb,0,SEEK_SET);
	read(fb,s,sizeof(s));
	for(int i=0;i<3;i++)
	{
		printf("%s %s %f\n",s[i].num,s[i].name,s[i].score);
	}
	return 0;	
}


