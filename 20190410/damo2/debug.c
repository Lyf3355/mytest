#include<stdio.h>
#define DEBUG
int main()
{
	int i=5;
#ifdef DEBUG
	printf("this is debug . i=%d",i);
#endif
	return 0;
}
