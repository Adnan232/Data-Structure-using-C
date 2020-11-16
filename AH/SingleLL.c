#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head = NULL;

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Node data : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node*ptr;
        ptr=head;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }   
}

int length()
{
    int count=0;
    struct node* temp;
    temp=head;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void insertBeg()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Node data : ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;//right connection (storing value of first node)
        head=temp;//left connection (linking new node to first node) 
    }
}
void insertAny()
{
    struct node* temp,*ptr;
    int loc,len,i=1;
    printf("\nEnter Location : ");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("\nInvalid Location\n");
        printf("Currently List is having %d nodes.",len);
    }
    else
    {
        ptr=head;
        while (i<loc)
        {
            ptr=ptr->next;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Node data : ");
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp->next=ptr->next;//right connection
        ptr->next=temp;//left connection
    }
}

void deleteAny()
{
    struct node* temp;
    int loc;
    printf("\n\nEnter Location of Node to delete : ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("\nLocation Invalid\n");
    }
    else if(loc==1)
    {
        temp=head;
        head=temp->next;
        temp->next=NULL;
        free(temp);
    }
    else
    {
        struct node* ptr=head, *q;
        int i=1;
        while (i<loc-1)
        {
            ptr=ptr->next;
            i++;
        }
        q=ptr->next;
        ptr->next=q->next;
        q->next=NULL;
        free(q);
        printf("\nNode has been Deleted ");
    }
    
}

void deleteEnd()
{
    struct node* ptr=head, *q;
        int i=1;
        while (i<length()-1)
        {
            ptr=ptr->next;
            i++;
        }
        q=ptr->next;
        ptr->next=q->next;
        q->next=NULL;
        free(q);
        printf("\nNode has been Deleted \n");
}
void deleteBeg()
{
    struct node* temp;
    temp=head;
    head=temp->next;
    temp->next=NULL;
    free(temp);
}

void display()
{
    struct node* temp;
    temp=head;
    if(temp==NULL)
    {
        printf("\nNo nodes present in list...\n");
    }
    else
    {
        printf("\nLink List : \n");
        while (temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    append();
    append();
    append();
    append();
    display();
    insertAny();
    display();
    insertBeg();
    display();
    deleteAny();
    display();
    deleteEnd();
    display();
    deleteBeg();
    display();
    return 0;
}