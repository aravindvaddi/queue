#include <stdio.h>
#include "queue.h"

int main ()
{
	int i;
	queue *q = NULL;

	printf("Before creating:\n");
	printf("%s\n\n", q ? "queue exists" : "queue doesn't exist");

	q_create(&q);

	printf("After creating:\n");
	printf("%s\n\n", q ? "queue exists" : "queue doesn't exist");

	printf("Before enqueuing:\n");
	q_print(q);
	printf("Front of queue: %d\n", q_front(q));
	printf("Length: %d\n\n", q_length(q));

	printf("enqueuing 10 elements:\n");

	for(i = 0; i < 10; i++)
	{
		q_push(q, i);
		q_print(q);
		printf("Front of queue: %d\n", q_front(q));
		printf("Length: %d\n\n", q_length(q));
	}

	printf("Popping 10 elements:\n");
	for(i = 10; i > 0; i--)
	{
		q_pop(q);
		q_print(q);
		printf("Front of queue: %d\n", q_front(q));
		printf("Length: %d\n\n", q_length(q));
	}

	printf("After popping:\n");
	q_print(q);
	printf("Front of queue: %d\n", q_front(q));
	printf("Length: %d\n\n", q_length(q));

	printf("Before destroying:\n");
	printf("%s\n\n", q ? "queue exists" : "queue doesn't exist");

	q_destroy(&q);

	printf("After destroying:\n");
	printf("%s\n\n", q ? "queue exists" : "queue doesn't exist");

	return 0;
}
