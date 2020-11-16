#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int cqueue[MAX];
int front=-1,rear=-1;
int size=0;
void enQueue(int ele)
{
    if((front==rear+1)||(rear==MAX-1))
    {
        printf("\ncQueue is Full.\n");
    }
    else if((front==-1)&&(rear==-1))
    {
        front=0;
        rear=0;
        cqueue[rear]=ele;
        size++;
    }
    else if(rear=MAX-1)
    {
        rear=0;
        cqueue[rear]=ele;
        size++;
    }
    else
    {
        rear++;
        cqueue[rear]=ele;
        size++;
    }
}
void deQueue()
{
    int ele;
    if(front==-1&&rear==-1)
    {
        printf("\ncQueue is Empty.\n");
    }
    else if(front==rear)
    {
        ele=cqueue[front];
        front=rear-1;
        size--;
    }
    else if(front=MAX-1)
    {
        ele=cqueue[front];
        front=0;
        size--;
    }
    else
    {
        int ele=cqueue[front];
        front++;
        size--;
    }
}
void display()
{
    if(front==-1&&rear==-1)
    {
        printf("\ncQueue is Empty.\n");
        return;
    }
    if(rear >= front) 
    {
        for(int i = 0; i <= rear; i++) 
        {
            printf("%d ", cqueue[i]);
        }
    } 
    else 
    {
        for(int i = front; i < size; i++) 
        {
            printf("%d ", cqueue[i]);
        }
        for(int i = 0; i <= rear; i++) 
        {
            printf("%d ", cqueue[i]);
        }
    }
    printf("\n");
    // if((front==0)&&(rear==MAX-1))
    // {
    //     for(int i=0;i<rear;i++)
    //     {
    //         printf("%d ",cqueue[i]);
    //     }
    // }
    // else
    // {
    //     for(int i=0;i<=rear;i++)
    //     {
    //         printf("%d ",cqueue[i]);
    //     }
    //     for(int i=front;i<MAX;i++)
    //     {
    //         printf("%d ",cqueue[i]);
    //     }
    // }
}

int main()
{
    enQueue(1);
    enQueue(2);
    enQueue(3);
    // enQueue(4);
    display();

    return 0;
}