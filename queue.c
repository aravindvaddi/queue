#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* function to check if queue is empty */

int q_empty (queue *q)
{
	if(q)
		return (!q->head) ? 1 : 0;
}

/* function to print queue */

void q_print (queue *q)
{
	node *temp;
	if(q)
	{
		temp = q->head;

		while(temp)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}

		printf("\n");
	}
}

/* function to return length of queue */

int q_length (queue *q)
{
	int i;
	node *temp;

	if(q)
	{
		temp = q->head;
		for(i = 0; temp; i++, temp = temp->next);
	}

	return i;
}

/* function to initialize a queue pointer */

void q_create (queue **q)
{
	*q = malloc(sizeof **q);
	(*q)->head = (*q)->tail = NULL;
}
