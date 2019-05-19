#include<func.h>

//void SignHandler(int iSignNo)
//{
//	printf("%d\n",iSignNo);
//}
int main()
{
	signal(SIGINT,SIG_IGN);
	while(1)
	{
		sleep(1);
	}
	return 0;
}
