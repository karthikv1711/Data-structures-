#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

typedef struct node NODE;

NODE *root = NULL;
NODE* insert(NODE *,int);
void inorder(NODE *);
void preorder(NODE *);
void postorder(NODE *);
void search(NODE*,int);
int  height(NODE*);
int  count(NODE*);
int main()
{
	int item,ch,key;
	while(1)
	{
		printf("\n*****MENU*****\n");
		printf("1. Insert\n");
		printf("2. Inorder\n");
		printf("3. Preorder\n");
		printf("4. Postorder\n");
		printf("5. Search\n");
		printf("6. Height\n");
		printf("7. Count nodes\n");
		printf("8. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be inserted : ");
				scanf("%d",&item);
				root = insert(root,item);
				break;
			
			case 2: inorder(root);
				break;
				
			case 3: preorder(root);
				break;
			
			case 4: postorder(root);
				break;
			
			case 5: printf("Enter the element to be searched : ");
				scanf("%d",&key);
				search(root,key);
				break;
				
			case 6: printf("Height of tree : %d",height(root));
				break;
				
			case 7: printf("Total Nodes : %d",count(root));
				break;
					
			case 8: exit(0);
				break;
				
			default: printf("INVALID CHOICE\n");
		}	
	}
}

NODE* insert(NODE *root,int item)
{
	if(root == NULL)
	{
		root = (NODE*)malloc(sizeof(NODE));
		root->data=item;
		root->lchild=NULL;
		root->rchild=NULL;
		return root;
	}
	
	else if(item >= root->data)
	{
		root->rchild=insert(root->rchild,item);
	}
	else
	{
		root->lchild=insert(root->lchild,item);
	}
	return root;
}

void inorder(NODE* root)
{
	if(root != NULL)
	{
		inorder(root->lchild);
		printf(" %d ",root->data);
		inorder(root->rchild);
	}
	
}

void preorder(NODE* root)
{
	if(root != NULL)
	{
		printf(" %d ",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void postorder(NODE* root)
{
	if(root != NULL)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf(" %d ",root->data);
	}
}

void search(NODE* root,int key)
{
	if(root == NULL)
		printf("Key is not found\n");
	else if(key == root->data)
		printf("Key is found \n");
	else if(key < root->data)
		search(root->lchild,key);
	else
		search(root->rchild,key);
}

int height(NODE *root)
{
	int lsh,rsh;     /* lsh = left side height , rsh=right side height */
	if(root == NULL)
		return 0;
	else
	{
		lsh = height(root->lchild);
		rsh = height(root->rchild);
		if(lsh > rsh)
			return (lsh+1);
		else
			return (rsh+1);
	}
}

int count(NODE* root)
{
	if(root == NULL)
		return 0;
	else
		return (count(root->lchild) + count(root->rchild) + 1);
}
