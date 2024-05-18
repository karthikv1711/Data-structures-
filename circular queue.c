/*  operation on queue's using arrays	*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insert(int);
void delete();
void display();
int front=-1;
int rear=-1;
int queue[SIZE];
int main()
{
	int item,choice;
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
				insert(item);
				break;
			case 2:	delete();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);			
				break;
			default: printf("INVALID CHOICE");
		}
	}
	
}

void delete()
{
	if(front == -1)
		printf("Queue is empty");
	else
	{
		printf("Deleted element = %d\n",queue[front]);
		if(front == rear)
			front=rear=-1;
		else
			front=(front+1)%SIZE;
	}
}

void insert(int item)
{
	if((rear+1)SIZE == front)
		printf("Queue is full\n");
	else
	{	if(front == -1)
			front = 0;
		rear = (rear+1)%SIZE;
		queue[rear] = item;
	}
}

void display()
{	
	int i;
	if(front == -1)
		printf("Queue is empty\n");
	else
	 {
		printf("Queue content : ");
		i=front;
		while(i != rear)
		{
			printf(" %4d ",queue[i]);
			i=(i+1)%SIZE;
		}
		printf(" %d",queue[rear]);
	 }
}