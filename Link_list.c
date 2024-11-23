
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////                 Link List                   /////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma warning(disable : warning_code)
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct node *next;
    struct node *prev;
}node;

/////////////////////////////////////////////////////   Insertion   ////////////////////////////////////////////////////////

node* insertion_from_last(node* head, int x)
{ 
    node *temp = head;
    node *new_node = (struct node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Memory not allocated.");
        return NULL;
    }
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(temp == NULL)
        return new_node;

    while(temp->next != NULL)
    {    temp = temp->next;}
    temp->next = new_node;
    new_node->prev = temp;
    return head;
}
node* insertion_from_begning(node* head, int x)
{
    node *temp = head;
    node *new_node = (struct node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Memory not allocated.");
        return NULL;
    }
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(temp == NULL)
        return new_node;

    new_node->next = temp;
    temp->prev = new_node;
    head = new_node;
    return head;
}
node* insertion_at_specific_position(node* head, int x,int pos)
{
    node *temp = head;
    node *temp2 = NULL;
    node *new_node = (struct node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Memory not allocated.");
        return NULL;
    }
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(temp == NULL)
        return new_node;

    int cnt=1;
    while(cnt != (pos-1))
    {
        temp = temp->next;
        cnt++;
    }
    new_node->prev = temp;
    new_node->next = (temp->next);
    temp2 = temp->next;
    temp->next = new_node;
    temp2->prev = new_node;
    return head;
}
node* insertion_after_given_node(node* head, int x,int data)
{
    node *temp = head;
    node *temp2 = NULL;

    while(temp->data != data)
    {
        temp = temp->next;      
        if(temp == NULL)
        {
            printf("enter correct value of Node. \n");
            return head;
        }  
    }

    node *new_node = (struct node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Memory not allocated.");
        return NULL;
    }
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(temp == NULL)
        return new_node;

    temp2 = temp->next;
    new_node->prev = temp;
    new_node->next = temp2;
    temp->next = new_node;
    temp2->prev = new_node;
    return head;
}
node* insertion_before_given_node(node* head, int x,int data)
{
    node *temp = head;
    node *temp2 = NULL;

    while(temp->data != data)
    {
        temp = temp->next;      
        if(temp == NULL)
        {
            printf("enter correct value of Node. \n");
            return head;
        }  
    }
    node *new_node = (struct node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Memory not allocated.");
        return NULL;
    }
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(temp == NULL)
        return new_node;

    temp2 = temp->prev;
    new_node->next = temp;
    new_node->prev = temp2;
    temp2->next = new_node;
    temp->prev = new_node;
    return head;
}

/////////////////////////////////////////////////////   Deletion   /////////////////////////////////////////////////////////

node* deletion_of_node(node* head, int value)
{
    node *temp = head;
    if(temp == NULL)
    {
        printf("link list is empty.");
        return head;
    }
    while(temp->data != value)
    {    
        if(temp == NULL)
        {
            printf("enter correct value of Node for deletion \n");
            return head;
        }
        temp = temp->next;   
    }

    node *temp2 = head;
    if(head->data == value)
    {
        head = head->next;
        head->prev = NULL;
        free(temp2);
    }
    else 
    {
        node *temp3 = temp->prev;
        node *temp4 = temp->next;
        temp3->next = temp4;
        temp4->prev = temp3;
        free(temp);
    }
    return head;
}   

/////////////////////////////////////////////////////   Display   /////////////////////////////////////////////////////////

void display(node* head)
{
    node *temp = head;
    if(temp == NULL)
        printf("LL is Empty");
    
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while (temp != NULL);
    printf("NULL \n");
}

/////////////////////////////////////////////////////   Main   /////////////////////////////////////////////////////////

int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;

    head = insertion_from_last(head,10);
    head = insertion_from_last(head,20);
    head = insertion_from_begning(head,30);
    head = insertion_from_last(head,40);
    head = insertion_from_last(head,50);
    head = insertion_from_last(head,70);
    head = insertion_at_specific_position(head,80,3);
    head = insertion_after_given_node(head,60,10);
    head = insertion_before_given_node(head,100,10);
    display(head);
    head = deletion_of_node(head,10);
    display(head);
}

