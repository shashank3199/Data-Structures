#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* right;
	struct Node* left;
}Node;

typedef Node* Nodeptr;

Nodeptr newNode(int data)
{
	Nodeptr temp = (Nodeptr)malloc(sizeof(Node));
	temp->data=data;
	temp->right=temp->left=NULL;
	return temp;
}

Nodeptr createNode(Nodeptr root,int data)
{
	if(root==NULL)
	{
		root = newNode(data);
		return root;
	}	
	Nodeptr ptr = root;
	int flag=0;
	while(ptr!=NULL)
	{
		if(data > ptr->data)
		{	
			if(ptr->right==NULL)
			{
				ptr->right = newNode(data);
				flag=-1;
				break;
			}
			ptr=ptr->right;
		}	
		else if(data<ptr->data)
		{
			if(ptr->left == NULL)
			{
				ptr->left = newNode(data);
				flag=-1;
				break;
			}
			ptr=ptr->left;
		}
		else
			break;
	}
	if(flag==0)
	ptr = newNode(data); 
	return root;
}

Nodeptr createBST(int val[],int n)
{
	Nodeptr root=NULL;
	for (int i = 0; i < n; ++i)
	{
		root = createNode(root,val[i]);
	}
	return root;
}

void inOrderRec(Nodeptr root)
{
	if(root!=NULL)
	{
		inOrderRec(root->left);
		printf("%3d ",root->data);
		inOrderRec(root->right);
	}
}

void Search(Nodeptr root,int data)
{
	if(root==NULL)
		return ;
	Nodeptr ptr = root;
	int flag=-1;
	while(ptr!=NULL)
	{
		if(data > ptr->data)
			ptr=ptr->right;
		else if(data<ptr->data)
			ptr=ptr->left;
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==-1)
		printf("Now Found.\n");
	else
		printf("Found.\n");
}

int main()
{
	int arr[]={9,5,4,7,8,6,2,3,1};
	Nodeptr root = NULL;
	root = createBST(arr,9);
	inOrderRec(root);	
	printf("\n");	
	return 0;
}