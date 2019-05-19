#ifndef __QUE_H__
#define __QUE_H__

#include "head.h"

typedef struct tag_node
{
    int newFd;
    struct tag_node *pNext;
}Node,*pNode;

typedef struct 
{
    pNode head;
    pNode tail;
    int queCapacity;
    int queSize;
    pthread_mutex_t mutex;
}Que,*pQue;
void queInit(pQue,int);
void queInsert(pQue,pNode);
int queGet(pQue,pNode*);
#endif


