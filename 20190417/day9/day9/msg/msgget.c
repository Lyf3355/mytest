#include <func.h>

int main()
{
	int msgId;
	msgId=msgget(1000,IPC_CREAT|0600);
	ERROR_CHECK(msgId,-1,"msgget");
	return 0;
}
