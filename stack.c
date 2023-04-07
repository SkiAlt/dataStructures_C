#include <stdio.h>
#include <stdlib.h>

typedef struct IntegerStack
{
        int *stk;
        int top;
        int MAX;
} Stack;

Stack create(int size)
{
        Stack s;
        s.stk = malloc(size * sizeof(int));
        s.MAX = size;
        s.top = -1;
        return s;
}

void display(Stack s)
{
        printf("\n");
        for (int i = s.top; i >= 0; i--)
        {
                printf("%d", s.stk[i]);
                if (i == s.top)
                        printf("  <-tos");
                printf("\n");
        }
}

void push(Stack *s, int ele)
{
        if (s->top == s->MAX - 1)
        {
                printf("Stack overflow\n");
                return;
        }
        s->top++;
        s->stk[s->top] = ele;
        Stack tempStack = *s;
        display(tempStack);
}

int pop(Stack *s)
{
        if (s->top == -1)
        {
                printf("Stack Underflow\n");
                return -1;
        }
        int temp = s->top--;
        Stack tempStack = *s;
        display(tempStack);
        return s->stk[temp];
}

int main()
{

        int size = 3;
        Stack s = create(size);
        push(&s, 5);
        push(&s, 10);
        push(&s, 15);
        push(&s, 20);
        printf("poping %d\n", pop(&s));
        printf("poping %d\n", pop(&s));
        printf("poping %d\n", pop(&s));
        display(s);
        printf("poping %d\n", pop(&s));
        display(s);
        return 0;
}