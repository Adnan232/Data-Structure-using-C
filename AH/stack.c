#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int top=-1;
int stack[MAX];

int isFull()
{
    if(top>=MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int peek()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top];
    }
    
}

void push(int item)
{
    if(!isFull())
    {
        top++;
        stack[top] = item;
        printf("\nElement has been Pushed\n");
    }
    else
    {
        printf("\n Stack is Full\n ");
    }
}

int pop()
{
    int element;
    if(!isEmpty())
    {
        element=stack[top];
        top--;
        return element;
    }
    else
    {
        printf("\nStack is Empty\n");
    }
}

void traverse()
{
    int i;
    if(!isEmpty())
    {
        printf("\nElements in Stacks are : ");
        for(i=top;i>=0;i--)
        {
            printf("\n\t %d ",stack[i]);
        }
    }
    else
    {
        printf("\nStack is empty\n");
    }
    
}
int main()
{
    int ch,ele;
    do
    {
        printf("\n1.Push into Stack");
        printf("\n2.Pop Element from stack");
        printf("\n3.Display Stack");
        printf("\n0.Exit");
        printf("\nEnter your Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nYou have selected choice 1...\n ");
                printf("\nEnter an Element : ");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                printf("\nYou have selected choice 2...\n ");
                printf("\nElement pop() is : %d",pop());    
                break;
            case 3:
                printf("\nYou have selected choice 3...\n ");
                traverse();
                break;
            case 0:
                printf("\nYou have selected choice 0...So Exiting...\n ");
                break;
            default:
                printf("\n\aYou Have selected invalid choice...\n");
                break;
        }
    } while(ch!=0);
    return 0;
}
