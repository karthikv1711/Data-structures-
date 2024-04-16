/* Stacks using arrays*/
#include<stdio.h>
#include<stdlib.h>
#define size 20
int stack[size],top=-1;
void push(int);
void pop();
void display();
int main()
{
	int choice,item;
	while(1)
	{
		printf("\nMENU\n");
		printf("1. PUSH\n");
 		printf("2. POP\n");	
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
	        {
	        	case 1: printf("Enter the element:");
	        		scanf("%d",&item);
	        		push(item);
	        		break;
	        		
	        	case 2: pop();
	        		break;
	        		
	        	case 3: display();
	        		break;
	        		
	        	case 4: exit(0);
	        	
	        	default: printf("INVALID CHOICE");		
	        }
	
	}


}

void push(int item)
{
	if(top == size-1)
		printf("STACK OVERFLOW");
	else
	{
		top=top+1;
		stack[top]=item;
		printf("Element inserted\n");		
	}

}

void pop()
{
	if(top == -1)
		printf("STACK UNDERFLOW");
	else
	{
		printf("Deleted element: %d",stack[top]);
		top--;
	}
}

void display()
{
	int i;
	if(top == -1)
		printf("STACK IS EMPTY");
	else
	{
		printf("STACK ELEMENTS: ");
		for(i=top;i>=0;i--)
			printf("%d ",stack[i]);
	}

}





























