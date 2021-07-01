#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
void insert(int value)
{
   struct node *ptr,*temp;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {    
        ptr->data=value;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
           printf("Inserted head\n");
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          printf("INSERTED\n");
       }  
   }
}
void insertionatspec(int value,int pos)
{
   struct node *ptr,*temp;  
   int i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       for(i=0;i<pos;i++)  
       {  
           temp = temp->next; 
       }  
       ptr->data = value;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("INSERTED\n");  
   }  
}
void search(int value)
{
    int i=0,flag=0;
    if(head==NULL)
    {
        printf("DLL IS EMPTY\n");
    }
    else
    {
        struct node *temp=head;
        if(temp->data==value)
        {
            printf("Data found at location %d\n",i+1);
            flag=0;
            exit(0);
        }
        else
        {
            flag=1;
        }
        i++;
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("%d is not found\n",value);
    }
}
void deleteatend()
{
    if(head==NULL)
    {
        printf("DLL is empty\n");
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        int item=temp->data;
        temp->prev->next=NULL;
        free(temp);
        printf("\n%d is deleted\n",item);
    }
}
void display()
{
    struct node *ptr;    
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}
void main()
{
    int ch,value,pos,s;
    do
    {
        printf("MENU\n");
        printf("1.Insert at particular pos\n2.Search an element\n3.Delete an element at end\n4.Insert normally\n5.Display\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the element to be inserted");
                scanf("%d",&value);
                printf("Enter the pos after which the node will be inserted:");
                scanf("%d",&pos);
                insertionatspec(value,pos);
                break;
            }
            case 2:
            {
                printf("Enter the value to be searched:");
                scanf("%d",&s);
                search(s);
                break;
            }
            case 3:
            {
                deleteatend();
                break;
            }
            case 4:
            {
                printf("Enter the value to be inserted:");
                scanf("%d",&value);
                insert(value);
            }
            case 5:
            {
                display();
                break;
            }
            default:
            {
                printf("INVALID INPUT");
                break;
            }
        }
    }while(ch!=0 && ch<6);
   
}