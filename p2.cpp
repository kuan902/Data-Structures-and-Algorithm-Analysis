#include<iostream>
#include<cstdlib>
using namespace std;
using ElemType=int;
struct Node
{
    ElemType data;
    struct Node *next;
};
Node* initList()
{
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}
int insertHead(Node* L,ElemType e)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
}
int main()
{
    Node *list=initList();
    insertHead(list,10);
    insertHead(list,20);
    return 1;
}
