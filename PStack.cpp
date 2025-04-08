#include <stdio.h>
#include <malloc.h>

struct Node {
    int Data;
    struct Node* Next;
};
typedef struct Node* Stack;

void makenullStack(Stack *s) {
    (*s) = (struct Node*) malloc (sizeof(struct Node));
    (*s)->Next = NULL;
}
int isEmpty(Stack s) {
    if(s->Next == NULL) return 1;
    else return 0;
}
struct Node* endList(Stack s) {
    struct Node* p = s;
    while(p->Next != NULL) {
        p = p->Next;
    }
    return p;
}
void push(int x, Stack *s) {
    struct Node* p = endList(*s);
    struct Node* t = (struct Node*) malloc (sizeof(struct Node));
    t->Next = p->Next;
    t->Data = x;
    p->Next = t;
}
struct Node* previous(struct Node* p, Stack s) {
    struct Node* t = s;
    while(t->Next != p) {
        t = t->Next;
    }
    return t;
}
void pop(Stack *s) {
    struct Node* p = previous(endList(*s), *s);
    printf("%d ", p->Next->Data);
    p->Next = endList(*s)->Next;
}
int peek(Stack s) {
    struct Node* p = endList(s);
    return p->Data;
}
void printSack(Stack s) {
    struct Node* p = previous(endList(s), s);
    while(p->Next != s->Next) {
        pop(&s);
        p = previous(p, s);
    }
    printf("\n");
}
int size(Stack s) {
    int cnt = 0;
    while(s->Next != NULL) {
        s = s->Next;
        cnt++;
    }
    return cnt-1;
}