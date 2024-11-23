
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////                 Queue                  /////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define QUEUE_SIZE   10

typedef struct 
{
    int Queue[QUEUE_SIZE];
    int F;
    int R;
}queue;

bool isfull(queue *eq)
{
    return ((eq->F == ((eq->R)+1)) || (eq->F==0 && eq->R==QUEUE_SIZE-1));
}

bool isempty(queue *eq)
{
    return eq->Queue[eq->F] == 0 && eq->Queue[eq->R] == 0;
} 

void Enque_from_rear(queue *eq,int data)
{
    int temp;
    if(eq->R == -1 && eq->F == -1)
    {
        eq->R = eq->F = 0;
        eq->Queue[eq->R] = data;
    }
    else if(isfull(eq))
    {
        printf("Queue is Full,\n");
    }
    else 
    {
        eq->R = (((eq->R)+1)%QUEUE_SIZE);
        temp = eq->R;
        eq->Queue[eq->R] = data;
    }
}

void Enque_from_front(queue *eq,int data)
{
    if(eq->R == -1 && eq->F == -1)
    {
        eq->R = eq->F = 0;
        eq->Queue[eq->F] = data;
    }
    else if(isfull(eq))
    {
        printf("Queue is Full.\n");
    }
    else if(eq->F == 0)
    {
        eq->F = QUEUE_SIZE-1;
        eq->Queue[eq->F] = data;
    }
    else 
    {
        eq->F = (((eq->F)-1));
        eq->Queue[eq->F] = data;
    }
}

int dequeue_from_front(queue *eq)
{
    if(isempty(eq))
    {
        printf("Queue is empty.\n");
    }
    else 
    {
        int data = eq->Queue[eq->F];
        printf("%d is dequeue from front. \n",data);
        eq->Queue[eq->F] = 0;
        eq->F = ((eq->F)+1)%QUEUE_SIZE;
        return data;
    }
}

int dequeue_from_rear(queue *eq)
{
    if(isempty(eq))
    {
        printf("Queue is empty.\n");
    }
    else if(eq->R == 0)
    {
        int data = eq->Queue[eq->R];
        printf("%d is dequeue from rear. \n",data);
        eq->Queue[eq->R] = 0;
        (eq->R) = QUEUE_SIZE-1;
        return data;
    }
    else 
    {
        int data = eq->Queue[eq->R];
        printf("%d is dequeue from rear. \n",data);
        eq->Queue[eq->R] = 0;
        (eq->R)--;
        return data;
    }
}

void Display(queue *eq)
{
    int temp = eq->F;
    if(isempty(eq))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf(" \n");
        printf("NULL");
        while(eq->Queue[temp] != 0)
        {
            printf(" -> (%d)%d",temp,eq->Queue[temp]);
            temp = (temp+1)%QUEUE_SIZE;
        }
        printf("\n");
        printf(" \n");
    }
}

int main(void)
{
    queue *q1 = (queue*)malloc(sizeof(queue));
    memset(q1->Queue, 0, sizeof(q1->Queue));
    q1->F = -1;
    q1->R = -1;

    Enque_from_rear(q1,10);
    Enque_from_rear(q1,20);
    Enque_from_front(q1,30);
    Enque_from_front(q1,40);
    Enque_from_rear(q1,50);

    Display(q1);
    dequeue_from_front(q1);

    Display(q1);
    dequeue_from_rear(q1);

    Display(q1);
    dequeue_from_front(q1);
    
    Display(q1);
    dequeue_from_rear(q1);

    Display(q1);
    dequeue_from_rear(q1);

    Display(q1);
    return 0;

}
