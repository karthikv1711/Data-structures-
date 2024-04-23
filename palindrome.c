#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
char stack[MAX];
int top=-1;

void push(char item)
{
	stack[++top]=item;

}

char pop()
{
	return stack[--top];
}


int ispalindrome(char str[])
{
	int i,n;
	n=strlen(str);
	for(i=0;i<n/2;i++)
	{
		push(str[i]);
	}
	
	if(i%2 == 1)
		i=(n/2)+1;
	else
		i=n/2;
		
	while(str[i] != '\0')
	{
		char item;
		item=pop();
		if(item != str[i])
			return 0;
		 	 i++;
	} return 1;
}

int main()
{
	char str[MAX];
	printf("input string :\n");
	scanf("%c",str);
	if(ispalindrome(str))
		printf("Given string is a palindrome");
	else
		printf("Given string is not a palindrome");
}

