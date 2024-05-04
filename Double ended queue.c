#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int dequeue[SIZE];
int front=-1,rear=-1;

void enqueue_front(int);
void enqueue_rear(int);
void delete_front();
void delete_last();
void display();

int main()
{
	int item,choice;
	while(1)
	{
		printf("****MENU****\n");
		printf("1. Enqueue Front\n");
		printf("2. Enqueue Rear\n");
		printf("3. Dequeue Front\n");
		printf("4. Dequeue Rear\n");
		printf("5. Display\n");
		printf("6. EXIT\n");
		printf("ENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("Enter the element to be inserted : ");
				scanf("%d",&item);
				enqueue_front(item);
				break;
		
			case 2: printf("Enter the element to be inserted : ");
				scanf("%d",&item);
				enqueue_rear(item);
				break;
			
			case 3: delete_front();
				break;
				
			case 4: delete_last();
				break;
				
			case 5: display();
				break;
				
			case 6: exit(0);
				break;
				
			default: printf("\nINVALID CHOICE\n");
		}
	}	
}

void enqueue_front(int item)
{
	if((rear+1)%SIZE == front)
		printf("Dequeue is full\n");
	else if(front == -1)
	{
		front=rear=0;
		dequeue[front]=item;	
	}
	else if(front == 0)
	{
		front = SIZE-1;
		dequeue[front] = item;
	}
	else
	{
		front = front-1;
		dequeue[front] = item;
	}
}

void enqueue_rear(int item)
{
	if((rear+1)%SIZE == front)
		printf("Dequeue is Full\n");
	else if(front == -1)
	{
		front=rear=0;
		dequeue[rear] = item;
	}
	else
	{
		rear=(rear+1)%SIZE;
		dequeue[rear] = item;
	}
}

void delete_front()
{
	if(front == -1)
		printf("Dequeue is empty\n");
	else if(front == rear)
	{
		printf("Deleted element = %d \n",dequeue[front]);
		front=rear=-1;
	}
	else
	{
		printf("Deleted element = %d \n",dequeue[front]);
		front=(front+1)%SIZE;
	}
}

void delete_last()
{
	if(front == -1)
		printf("Dequeue is Empty\n");
	else
	{
		printf("Deleted element = %d \n",dequeue[rear]);
		
		if(front == rear)
			front=rear=-1;
		else if(rear == 0)
			rear=SIZE-1;
		else
			rear=rear-1;
	}
}

void display()
{
	int i;
	i=front;
	if(front == -1)
		printf("Dequeue is Empty\n");
	else
	{
		while(i != rear)
		{
			printf(" %4d ",dequeue[i]);
			i=(i+1)%SIZE;
		}
		printf(" %d \n",dequeue[rear]);
	}
}
