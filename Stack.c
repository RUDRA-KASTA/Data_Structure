
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////                 Stack                  /////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

typedef struct
{
    int data[STACK_SIZE]; 
    int top;
}stack;


bool isempty(stack *stack)
{
    return stack->top == -1;
}
bool isfull(stack *stack)
{
    return stack->top == STACK_SIZE-1;
}
void push (stack *stack, int x)
{
    if(isfull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        stack->data[++stack->top] = x;
    }
}
int pop(stack *stack)
{
    if(isempty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else 
    {
        int popvalue;
        popvalue = stack->data[stack->top--];
        return popvalue;
    }
    printf("1");
}

int peep(stack *stack)
{
    if(isempty(stack))
    {
        printf("stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
}

void display(stack *stack)
{
    if(isempty(stack))
    {
        printf("Stack is empty.\n");
    }
    while(stack->top != -1)
    {
        printf("%d ->",stack->data[stack->top]);
        stack->top--;
    }
    printf("Null \n");
}

int main(void)
{
    stack *stack1 = (stack*)malloc(sizeof(stack));
    stack1->top = -1;

    push(stack1,10);
    push(stack1,20);
    push(stack1,30);
    printf("%d \n",peep(stack1));
    push(stack1,40);
    push(stack1,50);
    pop(stack1);
    display(stack1);
    return 0;
}


