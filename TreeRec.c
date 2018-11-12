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

Nodeptr insertAtPos(Nodeptr root,int data,char *pos)
{
	Nodeptr ptr = root;
	for(int j=0;pos[j]!='\0';j++)
	{
		if(pos[j] == 'l')
		{
			if(ptr->left == NULL)
			{
				ptr->left = newNode(data);
				return root;
			}
			ptr= ptr->left;
		}
		if(pos[j]=='r')
		{
			if(ptr->right==NULL)
			{
				ptr->right = newNode(data);
				return root;
			}
			ptr=ptr->right;
		}
	}
	ptr = newNode(data);
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

void preOrderRec(Nodeptr root)
{
	if(root!=NULL)
	{
		printf("%3d ",root->data);
		preOrderRec(root->left);
		preOrderRec(root->right);
	}
}

void postOrderRec(Nodeptr root)
{
	if(root!=NULL)
	{
		postOrderRec(root->left);
		postOrderRec(root->right);
		printf("%3d ",root->data);
	}
}

int main()
{
	int arr[]={7,4,11,2,5,9,12,1,3,6,8,10};
	char *pos[] = {"","l","r","ll","lr","rl","rr","lll","llr","lrr","rll","rlr"};
	Nodeptr root;
	root = insertSpecificOrder(arr,pos,12);
	root = insertAtPos(root,14,"rrr");
	root = insertAtPos(root,13,"rrrl");
	inOrderRec(root);
	printf("\n");
	preOrderRec(root);
	printf("\n");
	postOrderRec(root);
	printf("\n");
	return 0;
}