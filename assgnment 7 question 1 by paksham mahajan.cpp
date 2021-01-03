/* ASSIGNMENT 7

        QUESTION 1
        
 PROGRAM FOR IMPLEMENTATION OF CIRCULAR QUEUE WITH ENQUEUE,
 DEQUEUE AND DISPLAY OPERATION
 */
 
#include<stdio.h>
#include<conio.h>

int cq[30];
int front=-1,rear=-1,size;

void display();
void enqueue(int);
void dequeue();

int main()
{
	int times,time,i,j,val;
	printf("enter the maximum elements you want to store in your circular queue\n");
    printf("or enter the size of circular queue <=30\n");
	scanf("%d",&size);
	
	printf("enter how many times you want to insert into circular queue\n");	
	printf("you can insert maximum %d times\n",size);
	scanf("%d",&times);
	
	for(i=0;i<times;i++)
	{
		printf("\nenter value you want to insert\n");
		scanf("%d",&val);
		enqueue(val);
		
		printf("circular queue at this moment is\n");
		display();
		
	}
	
	printf("\nenter how many times you want to delete from circular queue\n");	
	scanf("%d",&time);
	
	for(j=0;j<time;j++)
	{
		dequeue();
		printf("\ncircular queue at this moment is\n");
		display();
	}
	
	
    getch();
	return 0;	
 } 
 
 void enqueue(int x)
 {
 	if(front==(rear+1)%size)
 	{
 		printf("overflow condition i.e circular queue is full\n");
 		return ;	
	 }
	
 	else if(front==-1 && rear==-1)
 	{
 		front=0;
 		rear=0;
 		cq[rear]=x;	
	 }
 	else if(rear==size-1 && front!=0)
 	{
 		
 		rear=0;
 		cq[rear]=x;
	 }
	 
	 else
	 {
	 	rear=rear+1;
	 	cq[rear]=x;
	 }
	 
 }
 
 void dequeue()
 {
 	if(front==-1)
 	{
 		printf("underflow condition i.e circular queue is empty\n");
 		return ;
	 }
	 
	 int x;
	 x=cq[front];
	 
	 if(front==rear)
	 {
	 	front=-1;
	 	rear=-1;
	 }
	 else if(front==size-1)
	 {
	 	front=0;
	 }
	 else
	 {
	 	front=front+1;
	 }
	 
	 printf("\ndeleted item from circular queue is %d\n",x);
	 
 }
 
 void display()
 {
 	if(front==-1)
 	{
 		printf("underflow condition i.e circular queue is empty, so display cannot be done\n");
 		return ;
	 }
	 
	int i,j;
	
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",cq[i]);
		}
	 }
	 
	 else
	 {
	 	for(i=front;i<=size-1;i++)
	 	{
	 		printf("%d ",cq[i]);
		 }
		 
		 for(j=0;j<=rear;j++)
		 {
		 	printf("%d ",cq[j]);
		 }
	  } 
 	
 }
 
 
 
         
