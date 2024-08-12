#include <stdio.h>

#include <stdlib.h>
void main()
{
    int x;
    push(12);
    x = pop();
    x = peek();
    push(111);
    push(234);
    push(323);
    push(3593);
    push(3);
    x = pop();

    for(int i = 11; i < 123; i += 1)
    {
        push(i);
        x = pop();
    }

    for(int i = 2; i < 3; i += 1)
    {
        peek(i);
        x = pop();
    }
}
