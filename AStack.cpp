#include <stdio.h>
#define max 40
typedef struct {
    int Data[max];
    int top;
} Stack;

void makenullList(Stack *s) {
    s->top = max;
}
int isEmpty(Stack s) {
    return s.top == max;
}
// them phan tu vao trong stack
void push(int x, Stack *s) {
    s->Data[s->top - 1] = x;
    s->top--;
}
void pop(Stack *s) {
    printf("%d ", s->Data[s->top]);
    s->top++;
}
int size(Stack s) {
    return max - s.top;
}
int peek(Stack s) {
    return s.Data[s.top];
}
void printStack(Stack *s) {
    while(s->top != max) {
        printf("%d ", s->Data[s->top]);
        s->top++;
    }
    printf("\n");
}
