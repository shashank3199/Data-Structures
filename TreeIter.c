#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

typedef Node* Nodeptr;

Nodeptr newNode(int data)
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

Nodeptr insertSpecificOrder(int val[],char *pos[],int n)
{
	Nodeptr root = newNode(val[0]);
	Nodeptr ptr;
	int flag;
	for(int i=1;i<n;i++)
	{
		ptr = root;
		flag=0;
		for(int j=0;pos[i][j]!='\0';j++)
		{
			if(pos[i][j] == 'l')
			{
				if(ptr->left == NULL)
				{
					ptr->left = newNode(val[i]);
					flag=-1;
					break;					
				}
				ptr= ptr->left;
			}
			if(pos[i][j]=='r')
			{
				if(ptr->right==NULL)
				{
					ptr->right = newNode(val[i]);
					flag=-1;
					break;
				}
				ptr=ptr->right;
			}
		}
		if(flag==0)
		ptr = newNode(val[i]);
	}
	return root;
}

typedef struct Queue
{
	Nodeptr *arr;
	int front;
	int rear;
	int size;
}Queue;

Queue* initQueue(int size)
{
	Queue *q = malloc(sizeof(Queue));
	q->arr=(Nodeptr*)malloc(size*sizeof(Nodeptr));
	q->front=q->rear=-1;
	q->size=size;
	return q;
}

void insert(Queue *q,Nodeptr data)
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

Nodeptr delete(Queue *q)
{
	if(q->front==-1)
	{
		printf("Queue Empty.\n");
		return NULL;
	}
	Nodeptr val = q->arr[q->front];
	if(q->front==q->rear)
		q->rear=q->front=-1;
	else
		q->front++;
	return val;
}

typedef struct Stack
{
	Nodeptr *arr;
	int top; 
	int size;
}Stack;

Stack* initStack(int size)
{
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	s->arr = (Nodeptr*)malloc(sizeof(Nodeptr)*size);
	s->top=-1;
	s->size=size;
	return s;
}

void push(Stack *s, Nodeptr data)
{
	s->arr[++(s->top)]=data;
}

Nodeptr pop(Stack *s)
{
	return s->arr[s->top--];
}

void levelOrder(Nodeptr root)
{
	if(root==NULL)
		return;
	Nodeptr ptr = root;
	Queue *q = initQueue(100);
	do
	{
		printf("%3d ",ptr->data);
		if(ptr->left!=NULL)
		insert(q,ptr->left);
		if(ptr->right!=NULL)
		insert(q,ptr->right);
		ptr = delete(q);
	}while(q->front!=-1);
	printf("%3d ",ptr->data);
}

void inOrderIter(Nodeptr root)
{
	if(root==NULL)
		return;
	Nodeptr ptr = root;
	Stack *s = initStack(100);
	for(int i=0;i<2;i++)
	{
		do
		{
			while(ptr!=NULL)
			{
				push(s,ptr);
				ptr=ptr->left;
			}
			ptr=pop(s);
			printf("%3d ",ptr->data);
			ptr=ptr->right;
		}while(s->top!=-1);
		if(i==0)
		ptr=root->right;
	}	
	printf("%3d ",ptr->data);
}

void preOrderIter(Nodeptr root)
{
	if(root==NULL)
		return;
	Nodeptr ptr = root;
	Stack *s = initStack(100);
	push(s,ptr);
	while(s->top!=-1)
	{
		ptr = pop(s);
		printf("%3d ",ptr->data);
		if(ptr->right!=NULL)
			push(s,ptr->right);
		if(ptr->left!=NULL)
			push(s,ptr->left);
	}
}

void postOrderIter(Nodeptr root)
{
	if(root==NULL)
		return;
	Stack *s1 = initStack(100);
	Stack *s2 = initStack(100);
	Nodeptr ptr = root;
	push(s1,ptr);
	while(s1->top!=-1)
	{
		ptr = pop(s1);
		push(s2,ptr);
		if(ptr->left!=NULL)
			push(s1,ptr->left);
		if(ptr->right!=NULL)
			push(s1,ptr->right);
	}

	while(s2->top!=-1)
	{
		ptr = pop(s2);
		printf("%3d ",ptr->data);
	}
}

void OrderRec(Nodeptr root)
{
	if(root!=NULL)
	{
		OrderRec(root->left);
		OrderRec(root->right);
		printf("%3d ",root->data);
	}
}

int main()
{
	int arr[]={7,4,11,2,5,9,12,1,3,6,8,10};
	char *pos[] = {"","l","r","ll","lr","rl","rr","lll","llr","lrr","rll","rlr"};
	Nodeptr root;
	root = insertSpecificOrder(arr,pos,12);
	OrderRec(root);
	printf("\n");
	postOrderIter(root);
	printf("\n");
	return 0;
}