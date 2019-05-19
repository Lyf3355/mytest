#include<func.h>

int main(int argc,char* argv[])
{

	FILE *fp=popen("cat file","r");
	char buf[128]={0};
	while(fgets(buf,sizeof(buf),fp))
	{
		puts(buf);
	}
	pclose(fp);
	return 0;
}

