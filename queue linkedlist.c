/* implementation of queue's using singly linked list */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
void insert_last(int);
void delete_front();
void display();

NODE *head=NULL;

int main()
{
	int choice,item;
	while(1)
	{
		printf(" \n MENU \n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. display\n");
		printf("4. EXIT\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:	printf("Enter the element to be inserted : ");
				scanf("%d",&item);
				insert_last(item);
				break;
			case 2:	delete_front();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);			
				break;
			default: printf("INVALID CHOICE");
		}
	}
} 

void insert_last(int item)
{
	NODE *temp, *cur=head;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->data = item;
	if(head == NULL)
	{
		head = temp;
		temp->next = NULL;
	}
	else
	{
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = temp;
		temp->next = NULL;
	}
}

void delete_front()
{
	NODE *temp;
	if(head == NULL)
		printf("Queue is empty");
	else
	{
		temp = head;
		head = head->next;
		printf("deleted element %d",temp->data);
		free(temp);
	}
	
}

void display()
{
	NODE *temp = head;
	if(head == NULL)
		printf("Queue is empty");
	else
	{
		printf("Queue content : ");
		while(temp != NULL)
		{
			printf(" %d ",temp->data);
			temp = temp->next;
		}
	}
}
