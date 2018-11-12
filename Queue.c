#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int *arr;
	int front;
	int rear;
	int size;
}Queue;

Queue* initQueue(int size)
{
	Queue *q = malloc(sizeof(Queue));
	q->arr=(int*)malloc(size*sizeof(int));
	q->front=q->rear=-1;
	q->size=size;
	return q;
}

void insert(Queue *q,int data)
{
	if(q->rear==q->size-1)
	{
		printf("Queue Full.\n");
		return;
	}
	if(q->front==-1 && q->rear==-1)
		q->front=q->rear=0;
	else
		(q->rear)++;
	q->arr[q->rear]=data;
}

int delete(Queue *q)
{
	if(q->front==-1)
	{
		printf("Queue Empty.\n");
		return -100000;
	}
	int val = q->arr[q->front];
	if(q->front==q->rear)
		q->rear=q->front=-1;
	else
		q->front++;
	return val;
}

void Display(Queue q)
{
	if(q.front==-1)
	{
		printf("Queue Empty.\n");
		return ;
	}
	for (int i = q.front; i <= q.rear; ++i)
	{
		printf("%d\n",q.arr[i]);
	}
}

int main()
{
	Queue *Q = initQueue(100);
	for (int i = 0; i < 10; ++i)
	{
		insert(Q,10-i);
	}
	printf("%d\n",delete(Q));
	printf("%d\n",delete(Q));
	printf("Check\n");
	Display(*Q);
	return 0;
}
