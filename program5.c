#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
}
	*top,*top1,*temp;
void push(int element);
void pop();
void display();
int main()
{
	int n,choice;
	printf("\n Stack using linked list\n");
	printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
do
{
	printf("\n enter your choice :\t");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:printf("enter the element :\t");
		scanf("%d",&n);
		push(n);
		break;
	case 2:pop();
		break;
	case 3:display();
		break;
	case 4:printf("Exit\n");
		break;
	default:printf("invalid choice!\n");
		break;
	}
}
while(choice!=4);
return 0;
}
void push(int element)
{
	if(top==NULL)
	{
	top=(struct node*)malloc(1*sizeof(struct node));
	top->link=NULL;
	top->data=element;
	}
	else
	{
	temp=(struct node*)malloc(1*sizeof(struct node));
	temp->link=top;
	temp->data=element;
	top=temp;
	}
}
void pop()
{
	top1=top;
	if(top1==NULL)
	{
	printf("stack is empty");
	return;
	}
	else
	{
	top1=top1->link;
	printf("popped element is :%d\n",top->data);
	free(top);
	top=top1;
	}
}
void display()
{
	top1=top;
	if(top1==NULL)
	{
	printf("stack is empty");
	return;
	}
	printf("Stack elements: ");
	while(top1!=NULL)
	{
	printf("%d\t",top1->data);
	top1=top1->link;
	}
}
	
	
