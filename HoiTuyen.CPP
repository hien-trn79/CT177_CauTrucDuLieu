#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
struct Node {
    ElementType Element;
    struct Node* Next;
};
typedef struct Node Node;
typedef Node* Position;
typedef Position List;

void makenullList(List *l) {
    (*l) = (struct Node*) malloc (sizeof(struct Node));
    (*l)->Next = NULL;
}
Position endList(List l) {
    Position p = l;
    while(p->Next != NULL) {
        p = p->Next;
    }
    return p;
}
void append(ElementType x, List *l) {       // thêm phần tử x vào cuối danh sách
    Position p = endList(*l);
    Position t = (struct Node*) malloc (sizeof(struct Node));
    t->Element = x;
    t->Next = p->Next;
    p->Next = t;
}
void addFirst(ElementType x, List* l) {
    Position t = (struct Node*) malloc (sizeof(struct Node));
    Position p = *l;
    t->Next = p->Next;
    t->Element = x;
    p->Next = t;
}
void nhap(List *a) {
    int n; scanf("%d", &n);
    makenullList(a);
   for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        append(x, a);
    }
}
void in(List a) {
    Position p = a;
    while(p->Next != NULL) {
        printf("%d ", p->Next->Element);
        p = p->Next;
    }
    printf("\n");
}

void inNguoc(List a) {
    List b;
    makenullList(&b);
    Position p = a;
    while(p->Next != NULL) {
        addFirst(p->Next->Element, &b);
        p = p->Next;
    }
    in(b);
}
void deleteList(Position p, List *l) {
    Position t = (struct Node*) malloc (sizeof(struct Node));
    t = p->Next;
    p->Next = t->Next;
    free(t);
}
void sort(List *l) {
    Position i = *l;
    while(i->Next != NULL) {
        Position j = i->Next;
        while(j->Next) {
            if(i->Next->Element > j->Next->Element) {
                int x = i->Next ->Element;
                i->Next->Element = j->Next->Element;
                j->Next->Element = x;
            }
            j=j->Next;
        }
        i=i->Next;
    }
}
void xoaTrung(List *l) {
    Position i = *l;
    while(i->Next != NULL) {
        Position j = i->Next;
        while(j->Next != NULL) {
            if(i->Next->Element == j->Next->Element) deleteList(j, l);
            else j = j->Next;
        }
        i = i->Next;
    }
    inNguoc(*l);
}

List tuyen(List a, List b) {
    List c;
    makenullList(&c);
    Position i = a;
    while(i->Next != NULL) {
        Position j =b;
        int cnt = 0;
        while(j->Next != NULL) {
            if(i->Next->Element == j->Next->Element) cnt++;
            j = j->Next;
        }
        if(cnt != 0) addFirst(i->Next->Element, &c);
        i = i->Next;
    }
    return c;
}
int main() {
    List a; List b;
    makenullList(&a); makenullList(&b);
    nhap(&a); nhap(&b);
    xoaTrung(&a);
    xoaTrung(&b);
    List c = tuyen(a, b);
    in(c);
}