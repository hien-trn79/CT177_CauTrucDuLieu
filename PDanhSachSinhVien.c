#include <stdio.h>
// #include "plistlib.c"
#include <malloc.h>
#include <string.h>

typedef struct {        
    char ID[10];
    char Name[50];
    float R1, R2, R3;   
} Student;

typedef Student ElementType;
struct Node {
    ElementType Element;
    struct Node* Next;
};
typedef struct Node Node;
typedef struct Node* List;
List getList() {        // tra ve la 1 danh sach rong
    List a = (struct Node*) malloc (sizeof(struct Node));
    a->Next = NULL;
    return a;
}
struct Node* endList(List a) {
    if (a == NULL || a->Next == NULL) {
        // Danh sách rỗng hoặc chỉ có một node, trả về NULL
        return NULL;
    }
    struct Node* p = a;
    while (p->Next != NULL) {
        p = p->Next;
    }
    return p;
}

struct Node* locate(char id[], List a) {        // tra ve vi tri xuat hien dau tien cua id
    struct Node* p = a;
    while(p->Next != endList(a)) {
        if(strcmp(p->Next->Element.ID, id) == 0) return p;
        else p = p->Next;
    }
    return NULL;
}
int append(Student s, List *a) {
    struct Node* p = endList(*a);
    struct Node* t = (struct Node*) malloc (sizeof(struct Node));
    if(locate(s.ID, *a) == endList(*a)) {
        t->Next = p->Next;
        t->Element = s;
        p->Next = t;
        return 1;
    }
    return 0;
}
void xoa(char c[]) {
    size_t len = strlen(c);
    if(c[len-1] == '\n') c[len-1] = '\0';
}
List reaList() {
    int n; scanf("%d", &n);
    getchar();
    List a;
    getList(&a);
    for(int i=0; i<n; i++) {
        printf("Id: ");
        fgets(a->Element.ID, 10, stdin);
        xoa(a->Element.ID);
        printf("ho ten: ");
        fgets(a->Element.Name, 50, stdin);
        xoa(a->Element.Name);
        printf("diem 3 mon: ");
        scanf("%f%f%f", &a->Element.R1, &a->Element.R2, &a->Element.R3);
        getchar();
    }
}
void printList(List a) {
    struct Node* p = a;
    int i=0;
    while(p->Next != NULL){
        float s = (p->Element.R1 + p->Element.R2 + p->Element .R3) / 3;
        printf("%d - \t %s - \t\t\t %s - %.3f - %.3f - %.3f - %3f\n", i+1, p->Element.ID, p->Element.Name, p->Element.R1, p->Element.R2, p->Element
        .R3, s);
        p = p->Next;
        i++;
    }
}
