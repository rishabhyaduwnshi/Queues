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

int dequeue(struct Queue *q)
{
	int x;
	if(q->front == q->rear)
	printf("Queue is Empty ");
	else
	{
		q->front++;
		x = q->Array[q->front];
	}
	return x;
}


void displayQueue(struct Queue q)
{
	int i;
	for(i=q.front+1;i<=q.rear;i++)
	printf("%d ",q.Array[i]);
}

int main()
{
	struct Queue q;
	int n,i;
	
	createQueue(&q,10);
	
	enqueue(&q,15);
	enqueue(&q,52);
	enqueue(&q,3);
	enqueue(&q,65);
	enqueue(&q,10);
	enqueue(&q,75);
	enqueue(&q,5);
	enqueue(&q,100);
	printf("Initially Elements present in Queue are \n");
	displayQueue(q);
	
	
	printf("\n\nEnter the number of elements to delete from queue : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	dequeue(&q);
	
	printf("\nAfter deletion elements in Queue are : ");
	displayQueue(q);
	
}
