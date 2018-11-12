#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	int *arr;
	int top; 
	int size;
}Stack;

Stack* initStack(int size)
{
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	s->arr = (int*)malloc(sizeof(int)*size);
	s->top=-1;
	s->size=size;
	return s;
}

int isEmpty(Stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int isFull(Stack *s)
{
	if(s->top==s->size-1)
		return 1;
	else
		return 0;
}

void push(Stack *s, int data)
{
	if(isFull(s)==1)
	{
		printf("Stack Overflow.\n");
		return;
	}
	s->arr[++(s->top)]=data;
}

int pop(Stack *s)
{
	if(isEmpty(s)==1)
	{
		printf("Stack Underflow.\n");
		return -100000;
	}
	return s->arr[s->top--];
}

void Display(Stack s)
{
	if(isEmpty(&s)==1)
	{
		printf("Stack Underflow.\n");
		return ;
	}
	for(int i=0;i<=s.top;i++)
		printf("%d\n",s.arr[i]);
}

int main()
{
	Stack *s = initStack(100);
	for(int i=0;i<10;i++)
		push(s,10-i);
	Display(*s);
	return 0;
}