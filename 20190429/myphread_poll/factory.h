#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "head.h"
#include "que.h"
#include "tranfile.h"

typedef struct{
    pthread_t *pthid;
    int threadNumb;
    pthread_cond_t cont;
    Que que;
    short startflag;
}Factory,*pFactory;

void facInit(pFactory,int,int);
void facStart(pFactory);
int tcpInit(int *,char *,char*);
#endif


