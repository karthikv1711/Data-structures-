#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX],top=-1;

void push(int item)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow");
		exit(0);
	}
	else
	stack[++top]=item;
}

int pop()
{
	int item;
	if(top==-1)
		printf("STack Underflow");
	else
		{
			item=stack[top];
			top--;
			return item;
		
		}
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int main()
{
	char postfix[100],ch;
	int op1,op2,i,r;
	printf("Postfix Expression: ");
	scanf("%c",postfix);
	for(i=0;postfix[i] != '\0';i++)
	{
		ch=postfix[i];
		if(isalnum(ch))
			push(ch);
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+':	r=op1 + op2;
							break;
			
				case '-':	r=op1 - op2;
							break;
						
				case '*':	r=op1 * op2;
							break;
						
				case '/':	r=op1 / op2;
							break;
							
				case '%':	r=op1 % op2;
							break;
			}
			
			push(r);
		}
	}

	r=pop();
	if(!isEmpty())
		printf("Invalid Postfix Expression");
	else	
		printf("Result = %d\n",r);
	
	return 0;
}
