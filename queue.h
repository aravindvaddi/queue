#ifndef QUEUE_H
#define QUEUE_H

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *head;
	struct node *tail;
};

typedef struct node node;
typedef struct queue queue;

/* queue helper and debug functions */

void q_print (queue *q);
int q_length (queue *q);
int q_exists (queue *q);

/* queue core functions */

void q_push (queue *q); // enqueue operation
void q_pop (quque *q);	// dequeue operation
int q_front (quque *q);
int q_empty (queue *q);

/* creation and destruction functions to allocate and deallocate memory to a queue pointer */

void q_create (queue **q);
void q_destroy (queue **q);

#endif
