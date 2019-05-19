#include "function.h"

int recvCycle(int newfd,void *p,int len)
{
    int  total=0;
    int ret;
    char *pstart=(char*)p;
    while(total<len)
    {
        ret=recv(newfd,pstart+total,len-total,0);
        if(0==ret)
        {
            return -1;
        }
        total=total+ret;
    }
    return 0;
}

