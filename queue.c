#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* function to check if queue is empty */

int q_empty (queue *q)
{
	if(q)
		return (!q->head) ? 1 : 0;
}

/* function to initialize a queue pointer */

void q_create (queue **q)
{
	*q = malloc(sizeof **q);
	(*q)->head = (*q)->tail = NULL;
}
