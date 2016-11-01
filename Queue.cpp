#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10
typedef int Status;
typedef struct queue{
	int front,rear;
	QueueEntry entry[MAXQUEUE];
}Queue,*QueuePtr;
