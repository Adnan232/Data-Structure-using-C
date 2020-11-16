#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*head=NULL, *top=NULL;

void push()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Node : ");
    scanf("%d",&temp->data);
    temp->next=top;
    top=temp;
}

void pop()
{
    struct node* temp;
    if(top==NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        temp=top;
        top=temp->next;
        temp->next=NULL;
        free(temp);
        printf("\nElement popped\n");
    }
}

void display()
{
    struct node*temp;
    if(top==NULL)
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        temp=top;
        printf("\nDisplaying Stack : \n");
        while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    pop();
    push();
    push();
    push();
    push();
    display();
    pop();
    display();
    return 0;
}