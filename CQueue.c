#include<stdio.h>
#include<stdlib.h>

typedef struct CQueue
{
	int *arr;
	int front;
	int rear;
	int size;
}CQueue;

CQueue* initCQueue(int size)
{
	CQueue *q = malloc(sizeof(CQueue));
	q->arr=(int*)malloc(size*sizeof(int));
	q->front=q->rear=-1;
	q->size=size;
	return q;
}

void insert(CQueue *q,int data)
{
	if((q->rear==q->size-1)&&(q->rear+1==q->front))
	{
		printf("Queue Full.\n");
		return;
	}
	if(q->front==-1 && q->rear==-1)
		q->front=q->rear=0;
	else if(q->rear==q->size-1)
		q->rear=0;
	else
		(q->rear)++;
	q->arr[q->rear]=data;
}

int delete(CQueue *q)
{
	if(q->front==-1)
	{
		printf("Queue Empty.\n");
		return -100000;
	}
	int val = q->arr[q->front];
	if(q->front==q->rear)
		q->rear=q->front=-1;
	else if(q->front == q->size-1)
		q->front=0;
	else
		q->front++;
	return val;
}

void Display(CQueue q)
{
	if(q.front==-1)
	{
		printf("Queue Empty.\n");
		return ;
	}
	if(q.front<q.rear)
	{
		for (int i = q.front; i <= q.rear; ++i)
		{
			printf("%d\n",q.arr[i]);
		}
	}
	else
	{
		for (int i = q.front; i < q.size; ++i)
		{
			printf("%d\n",q.arr[i]);
		}
		for (int i = 0; i <= q.rear; ++i)
		{
			printf("%d\n",q.arr[i]);
		}
	}
}

int main()
{
	CQueue *Q = initCQueue(10);
	for (int i = 0; i < 10; ++i)
	{
		insert(Q,i);
	}
	printf("%d\n",delete(Q));
	printf("%d\n",delete(Q));
	printf("Check\n");
	insert(Q,0);
	insert(Q,1);
	printf("%d\n",delete(Q));
	printf("%d\n",delete(Q));
	printf("Check2\n");
	insert(Q,8);
	insert(Q,9);
	printf("%d\n",delete(Q));
	printf("%d\n",delete(Q));
	printf("Check3\n");
	Display(*Q);
	return 0;
}
