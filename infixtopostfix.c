/*Conversion of infix expression to postfix expression */
#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;

void push(char item)
{
	top=top+1;
	stack[top]=item;
}

char pop()
{
	if(top==-1)
		return -1;
	else
		return stack[top--];
}

int priority(char ch)
{
	if(ch=='(')
		return 0;
	if(ch=='+' || ch=='-')
		return 1;
	if(ch=='*' || ch=='/' || ch=='%')
		return 2;
}

int main()
{
	char infix[100],ch,x;
	int i;
	printf("Infix expresssion: ");
	scanf("%s",infix);
	printf("Postfix Expression: ");
	for(i=0;infix[i] != '\0';i++)
	{
		ch=infix[i];
		if(isalnum(ch))
			printf("%c",ch);
		else if(ch=='(')
			push(ch);
		else if(ch == ')')
		{
			while((x=pop()) != '(')
				printf("%c",x);
		}	
		else
		{
			while(priority(stack[top]) >= priority(ch))
				printf("%c",pop());
				push(ch);		
		
		}
	}

	while(top != -1)
		printf("%c",pop());
	printf("\n");
		
}
