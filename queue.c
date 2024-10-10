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
	printf("select the option :\t");
	scanf("%d",&opt);
switch(opt)
	{
	case 1:
	printf("enter the item to be inserted :\t");
	scanf("%d",&item);
	ENQUEUE(item);
	break;
	case 2:
	DEQUEUE();
	break;
	case 3:
	DISPLAY();
	break;
	case 4:
	printf("EXIT\n");;
	break;
	default:
	printf("invalid option");
	}
}
while(opt!=4);
return 0;
}
void ENQUEUE(int item)
{
	if(rear==size-1)
	{
	printf("queue is full\n");
	}
	else if(rear==-1)
	{
	rear=0;
	front=0;
	A[rear]=item;
	}
	else
	{
	rear++;
	A[rear]=item;
	}
}

void DEQUEUE()
{
	if(front==-1)
	{
	printf("queue is empty");
	}
	else if(front==rear)
	{
	printf("Deleted item is :%d\t",A[front]);
	front==-1;
	rear==-1;
	}
	else
	{
	printf("Deleted item is :%d\t",A[front]);
	front++;
	}
}
void DISPLAY()
{
	int i;
		if(front==-1)
		{
		printf("\n queue is empty\n");
		}
		else
		{
		for(i=front;i<=rear;i++)
		{
		printf("\n%d \n",A[i]);
		}
		}
}
		
