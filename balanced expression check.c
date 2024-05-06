/* to check whether the given expression is balanced or not */
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
char stack[MAX];
int top=-1;

void push(char item)
{
	if(top == MAX-1)
		printf("Stack Overflow\n");
	else
		stack[++top]=item;
}

int isMatch(char ch1, char ch2)
{
	if(ch1 == '{' && ch2 == '}')
		return 1;
	else if(ch1 == '[' && ch2 == ']')
		return 1;
	else if(ch1 == '(' && ch2 == ')')
		return 1;
	else
		return 0;
}

char pop()
{
	char ch;
	if(top == -1)
	{
		printf("UnBaalanced\n");
		exit(0);
	}
	else
	ch = stack[top--];
	return ch;	
}

int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

int main()
{
	char exp[MAX],temp,ch;
	int i;
	printf("Enter the expression : ");
	scanf("%s",exp);
	for(i=0; exp[i] != '\0'; i++)
	{
		ch = exp[i];
		if(ch == '{' || ch == '[' || ch == '(')
			push(ch);
		else
		{
			temp = pop();
			if(!isMatch(temp,ch))
			{
				printf("UnBalanced Expression \n");
				exit(0);
			}	
		}
	}

	if(isEmpty)
		printf("Balanced expression \n");
	else
		printf("UnBalanced expression");
}
