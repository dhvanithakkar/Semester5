#include <stdio.h>

#include <stdlib.h>

#define SIZE 4

int top = -1, inp_array[SIZE];
void push(int x);
int pop();
void show();
int peek();

int main()
{
    int choice;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Peek\n4.Show\n5.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        int x;

        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be added onto the stack: ");
            scanf("%d", &x);

            push(x);
            break;
        case 2:
            x = pop();        
            printf("\nPopped element: %d", x);

            break;
        case 3:
            x = peek();
            printf("\nTop element: %d", x);

            break;
        case 4:
            show();

            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push(int x)
{
    if (top == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        top = top + 1;
        inp_array[top] = x;
    }
}

int pop()
{
    int x;
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        x = inp_array[top];
        top = top - 1;
    }
    return x;
}

int peek()
{
    int x;
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        x = inp_array[top];
    }
    return x;
}


void show()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}


void main()
{
    int x;
    push(12);
    x = pop();
    x = peek();
    push(111);
    push(234);
    pop();

    for(int i = 11; i <= 123; i += 2)
    {
        push(i);
        if(i % 3 == 0)
        {
            x = pop();
        }
        x = peek();
    }

    for(int i = 11; i <= 123; i += 2)
    {
        push(i);
        i *= 2;
        if(i % 3 == 0)
        {
            x = pop();
        }
        x = peek();
    }

    for(int i = 1; i <211; i *= 3)
    {
        push(i);
        i --;
        if(i == 3)
        {
            x = pop();
        }
        x = peek();
    }

    for(int i = 0; i < 2; i++)
        x = pop();
    
    for(int i = 1; i < 333; i *= 2)
        if(i == 8)
            push(222);
    
    for(int i = 1290; i > -1; i--)
        switch (i % 3)
        {
            case 0: push(0); break; 
            case 1: x = pop(); break; 
            case 2: push(2); break;
        }
}
