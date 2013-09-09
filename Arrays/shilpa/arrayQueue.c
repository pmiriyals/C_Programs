#include<stdio.h>
#include<stdlib.h>

#define size 10

int* createQueue()
{
	return calloc(size, sizeof(int));
}

int increment(int num)
{
	return (num+1)%size;
}

void enQueue(int* queue, int* rear, int* front, int num)
{
	if(*rear == *front)
	{
		printf("\n queue overflow");
		return;
	}
	queue[*rear] = num;	
	*rear = increment(*rear);
}

int deQueue(int* queue, int* rear, int* front)
{	
	*front = increment(*front);
	if(*front == *rear)
	{
		printf("\n queue under flow");
		return -1;
	}
	int num = queue[*front];	

	return num;
}

void main()
{
	int* queue = createQueue();
	int front = 0;
	int rear = 1;

	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int l = sizeof(arr)/sizeof(int);
	int i;
	for(i = 0; i<l;i++)
	{
		enQueue(queue, &rear, &front, arr[i]);
	}
	for(i = 0; i < l; i++)
	{
		int num = deQueue(queue, &rear, &front);
		if(num == -1)
			break;
		printf("\n %d", num);
	}
	printf("\n rear = %d\n front = %d\n", rear, front);
}
