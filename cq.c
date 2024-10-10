#include<stdio.h>
int A[20],size,front=-1,rear=-1;
void ENQUEUE(int item);
void DEQUEUE();
void DISPLAY();
int main()
{
	int item,opt;
	printf("enter the size of the queue :\t");
	scanf("%d",&size);
	printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
do
{
	printf("\nenter the option :\t");
	scanf("%d",&opt);
switch(opt)
	{
	case 1:printf("enter the item to be inserted :");
		scanf("%d",&item);
		ENQUEUE(item);
		break;
	case 2:DEQUEUE();
		break;
	case 3:DISPLAY();
		break;
	case 4:printf("EXIT\t");
		break;
	default:printf("invalid option\n");
	}
}
while(opt!=4);
return 0;
}
void ENQUEUE(int item)
{
	if((rear+1)%size==front)
	printf("queue is full.insertion is not possible");
	else if(rear==-1)
	{
	front=0;
	rear=0;
	A[rear]=item;
	}
	else
	{
	rear=(rear+1)%size;
	A[rear]=item;
	}
}
void DEQUEUE()
{
	if(front==-1)
	printf("queue is empty");
	else if(front==rear)
	{
	printf("deleted item is :%d",A[front]);
	front==-1;
	rear==-1;
	}
	else
	{
	printf("deleted item is :%d",A[front]);
	front=(front+1)%size;
	}
}
void DISPLAY()
{
	int i;
	if(front==-1)
	printf("queue is empty");
	else
	{
	for(i=front;i!=rear;i=(i+1)%size)
	{
	printf("%d\t",A[i]);
	}
	printf("%d",A[i]);
	}
}
	
	

