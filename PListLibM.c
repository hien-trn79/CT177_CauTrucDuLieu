#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef int ElementType;
struct Node {
    ElementType Element;
    struct Node* Next;
};
typedef struct Node Node;
typedef Node* Position;
typedef Position List;

void makenullList(List *header) {    // khoi tao danh sach rong
    (*header) = (struct Node*) malloc (sizeof(struct Node));
    (*header)->Next = NULL;
}   
int emptyList(List a) {     // kiem tra danh sach rong
    return a->Next == NULL;
}
Position first(List a) {        // tra ve vi tri dau cua danh sach
    return a;
}
Position endList(List l) {      // tra ve vi tri cuoi cua danh sach
    Position p = l;
    while(p->Next != NULL) {
        p = p->Next;
    }
    return p;
}
Position next(Position p, List a) {
    return p->Next;
}
Position previous(Position p, List a) {
    Position i = a;
    while(i->Next != NULL) {
        if(i->Next == p) break;
    }
    return i;
}
void append(ElementType x, List *a) {       // chen phan tu x vao cuoi danh sach
    Position p = endList(*a);
    Position t = (struct Node*) malloc (sizeof(struct Node));
    t->Element = x;
    t->Next = p->Next;
    p->Next = t;
}   
Position locate(ElementType x, List a) {        // tra ve vi tri dau tien cua x
    Position i;
    for(i = a; i->Next != NULL; i = i->Next) {
        if(i->Next->Element == x) return i;
    }
    return i->Next;
}
void deleteList(Position p, List *a) {      // xoa vi tri p
    Position t= (struct Node*) malloc (sizeof(struct Node));
    t = p->Next;
    p->Next = t->Next;
    free(t);
}   
void printList(List a) {        // in danh sach
    for(Position i = a; i->Next != NULL; i = i->Next) {
        printf("%d ", i->Next->Element);
    }
    printf("\n");
}
void sort(List *a) {    // sap xep tang dan
    Position i = *a;
    while(i->Next->Next != NULL) {
        Position j = i->Next;
        while(j->Next != NULL) {
            if(i->Next->Element > j->Next->Element) {
                int x = i->Next->Element;
                i->Next->Element = j->Next->Element;
                j->Next->Element = x;
            }
            j = j->Next;
        }
        i = i->Next;
    }
}
void erase(int phanTuXoa, List *danhSach) {     // xoa phan tu dau tien
    Position t = locate(phanTuXoa, *danhSach);
    if(t->Next != NULL) deleteList(t, danhSach);
    else printf("Not found %d\n", phanTuXoa);
}
void addFirst(ElementType x, List* a) {     // them vao dau danh sach
    Position t = (struct Node*) malloc (sizeof(struct Node));
    Position p = *a;
    t->Next = p->Next;
    p->Next = t;
    t->Element = x;
}
float getAvg(List a) {      // tinh trung binh
    float sum = 0.0f;
    int cnt = 0;
    Position p = a;
    while(p->Next != NULL) {
        sum += p->Next->Element;
        cnt++;
        p = p->Next;
    }
    if(cnt == 0) return -10000;
    else return sum/cnt;
}
void removeAll(ElementType x, List *a) {        // xoa tat ca x xuat hien trong danh sach
    Position p = locate(x, *a);
    while(p->Next != NULL) {
        deleteList(p, a);
        p = locate(x, *a);
    }
}
void readList(List *a) {        // nhap du lieu vao
    makenullList(a);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        append(t, a);
    }
}
void insertList(ElementType x, Position p, List *a) {       // chen phan tu
    Position t = (struct Node*) malloc (sizeof(struct Node));
    t->Next = p->Next;
    t->Element = x;
    p->Next = t;
}
int member(ElementType x, List a) {       // kiem tra phan tu x co trong danh sach hay khong?
    int cnt = 0;
    Position p = a;
    while(p->Next != NULL) {
        if(p->Next->Element == x)
            cnt++;
        p = p->Next;
    }
    if(cnt == 0) return 0;
    else return 1;
}
List readSortUp() {     // nhap co thu tu tang
    List a;
    makenullList(&a);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        int found = 0;
        Position j = a;
        while(j->Next != NULL && found == 0) {
            if(t <= j->Next->Element) {
                insertList(t, j, &a);
                found++;
            }
            else j = j->Next;
        }
        if(found == 0) insertList(t, endList(a), &a);
    }
    return a;
}
List readSortDown() {     // nhap co thu tu giam
    List a;
    makenullList(&a);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        int found = 0;
        Position j = a;
        while(j->Next != NULL && found == 0) {
            if(t >= j->Next->Element) {
                insertList(t, j, &a);
                found++;
            }
            else j = j->Next;
        }
        if(found == 0) insertList(t, endList(a), &a);
    }
    return a;
}
List readSet() {  // chen phan tu neu chua co trong danh sach
    List a;
    makenullList(&a);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        if(member(t, a) == 0) addFirst(t, &a);
    }
    return a;
}
List nhap() {       // nhap thong tin danh sach
    List a;
    makenullList(&a);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int t; scanf("%d", &t);
        append(t, &a);
    }
    return a;
}
void soChan(List a) {       // in trung binh cua nhung so chan trong danh sach
    float sum = 0.0f;
    int cnt = 0;
    for(Position i=a; i->Next != NULL; i=i->Next) {
        if(i->Next->Element % 2 == 0) {
            sum+= i->Next->Element;
            cnt++;
            printf("%d ", i->Next->Element);
        }
    }
    printf("\n%.3f", sum/cnt);
}
ElementType phanTuMax(List a) {     // tim phan tu max
    int max = -1000;
    Position p = a;
    while(p->Next != NULL ) {
        if(p->Next->Element > max) max = p->Next->Element;
    }
    return max;
}
ElementType phanTuMin(List a) {     // tra ve phan tu min
    int min = 1000;
    Position p = a;
    while(p->Next != NULL ) {
        if(p->Next->Element > min) min = p->Next->Element;
    }
    return min;
}
void Slplit_List(List a, List *b, List *c) {       // tach thanh 2 danh sach chan le
    makenullList(b);    // danh sach chua so chan
    makenullList(c);    // danh sach chua so le
    Position p = a;
    while(p->Next != NULL) {
        if(p->Next->Element %2 == 0) append(p->Next->Element, b);
        else append(p->Next->Element, c);
    }
}
List mergeSortUp(List a, List b) {  // tron danh sach theo thu tu tang
    List c;
    makenullList(&c);
    Position i = a;
    Position j = b;
    while(i->Next != NULL && j->Next != NULL) {
        if(i->Next->Element < j->Next->Element) {
            append(i->Next->Element, &c);
            i = i->Next;
        } else {
            append(j->Next->Element, &c);
            j = j->Next;
        }
    }
    while(i->Next != NULL) {
        append(i->Next->Element, &c);
        i= i->Next;
    }
    while(j->Next != NULL) {
        append(j->Next->Element, &c);
        j = j->Next;
    }
    return c;
}