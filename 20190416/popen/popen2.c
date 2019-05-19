#include<func.h>

int main(int argc,char* argv[])
{

	FILE *fp=popen("wc -w file","w");
	char buf[128]={"hello the world"};
	fwrite(buf,sizeof(buf),3,fp);
	pclose(fp);
	return 0;
}

