#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int size;
	int front;
	int rear;
	int *Array;
};

void createQueue(struct Queue *q,int x)
{
	q->size = x;
	q->front = -1;
	q->rear = -1;
	q->Array = (int *)malloc(x*sizeof(int));
}

void enqueue(struct Queue *q,int x)
{
	if(q->rear == q->size-1)
	printf("Queue is Full");
	else
	{
		q->rear++;
		q->Array[q->rear] = x;
	}
}

void displayQueue(struct Queue q)
{
	int i;
	for(i=0;i<=q.rear;i++)
	printf("%d ",q.Array[i]);
}

int main()
{
	struct Queue q;
	int x,n,data,i;
	printf("Enter size : ");
	scanf("%d",&x);
	createQueue(&q,x);
	
	printf("Enter the number of elements to enqueue : ");
	scanf("%d",&n);
	
	for(i=q.front+1;i<n;i++)
	{
		scanf("%d",&data);
		enqueue(&q,data);
	}
	printf("Elements present in Queue are : ");
	displayQueue(q);
}
