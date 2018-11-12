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

Nodeptr insertLevelOrder(Nodeptr root,int *val,int pos,int n)
{
	if(pos<n)
	{
		root = newNode(val[pos]);
		root->left = insertLevelOrder(root->left,val,2*pos+1,n);
		root->right = insertLevelOrder(root->right,val,2*pos+2,n);
	}
	return root;
}

void inOrder(Nodeptr root)
{
	if(root == NULL)
		return ;
	inOrder(root->left);
	printf("%3d ",root->data);
	inOrder(root->right);
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

void topView(Nodeptr root)
{
	if(root==NULL)
		return;
	Stack *s = initStack(100);
	Nodeptr ptr = root;
	while(ptr!=NULL)
	{
		push(s,ptr);
		ptr=ptr->left;
	}	
	while(s->top!=-1)
		printf("%3d ",pop(s)->data);
	ptr=root->right;
	while(ptr!=NULL)
	{
		printf("%3d ",ptr->data);
		ptr=ptr->right;
	}	
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	Nodeptr root = insertLevelOrder(root,arr,0,7);
	inOrder(root);
	printf("\n");
	topView(root);
	printf("\n");
	return 0;
}