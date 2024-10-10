#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push();
void pop();
void display();
int main()
{
	top=-1;
	printf("\n enter the size of stack");
	scanf("%d",&n);
	printf("\n\t stack operations using array");
	printf("\n\t 1.push \n\t 2.pop \n\t 3.display \n\t 4.exit ");
	do{
	printf("\n enter the choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: push();
		break;
		case 2: pop();
		break;
		case 3: display();
		break;
		case 4: printf("\n\t exit");
		break;
		default:
		{
		printf("\n enter valid choice (1/2/3/4)");
		}
	}
}
		while(choice!=4);
		return 0;
}
	void push()
		{
		if(top==n-1)
		{
		printf("\n stack overflow");
		}
		else
		{
		printf("\n enter value to be pushed");
		scanf("%d",&x);
		top++;
		stack[top]=x;
		}
		}
	void pop()
		{
		if(top==-1)
		{
		printf("\n\t stack underflow");
		}
		else
		{
		printf("\n\t popped element is %d",stack[top]);
		top--;
		}
		}
	void display()
		{
		if(top>=0)
		{
		printf("\n the element in stack\n");
		for(i=top;i>=0;i--)
		printf("\n%d \n",stack[i]);
		}
		else
		{
		printf("\n stack is empty");
		}
		}
