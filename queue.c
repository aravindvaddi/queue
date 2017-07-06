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

/* function to enqueue an element */

void q_push (queue *q, int data)
{
	node *temp;

	if(q)
	{
		temp = malloc(sizeof *temp);
		temp->data = data;
		temp->next = NULL;

		if(q_empty(q))
			q->head = q->tail = temp;
		else
			q->tail->next = temp;
	}
}

/* function to dequeue an element */

void q_pop (queue *q)
{
	node *temp;

	if(q && !q_empty(q))
	{
		temp = q->head;

		if(q_length(q) == 1)
			q->head = q->tail = NULL;
		else
			q->head = q->head->next;

		temp->data = 0;
		temp->next = NULL;
		free(temp);
		temp = NULL;
	}
}

/* function to return the element at the front of the queue */

int q_front (queue *q)
{
	if(q && !q_empty(q))
			return q->head->data;
}

/* function to initialize a queue pointer */

void q_create (queue **q)
{
	*q = malloc(sizeof **q);
	(*q)->head = (*q)->tail = NULL;
}

/* function to destroy a queue pointer */

void q_destroy (queue **q)
{
	if(*q)
	{
		while(!q_empty(*q))
			q_pop(*q);

		free(*q);
		*q = NULL;
	}
}
