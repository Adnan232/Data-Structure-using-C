#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=0,rear=0;

void insert()
{
    if(MAX==rear)
    {
        printf("\nQueue is Full\n");
    }
    else
    {
        int ele;
        printf("\nEnter Element : ");
        scanf("%d",&ele);
        queue[rear]=ele;
        rear++;
    }
}
void delete()
{
    int i;
    if(front==rear)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nDeleted Item is : %d\n",queue[front]);
        for(i=0;i<rear-1;i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
    }
}
void display()
{
    int i;
    if(front==rear)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nQueue Elements :\n");
        for(i=front;i<rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    delete();
    display();
    return 0;
}