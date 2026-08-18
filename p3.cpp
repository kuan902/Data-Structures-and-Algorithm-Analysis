#include<iostream>
using namespace std;
using ElemType=int;
struct Node
{
    ElemType data;
    Node *prev,*next;
};
Node* initList()
{
    Node *head=new Node;
    head->data=0;
    head->next=nullptr;
    head->prev=nullptr;
    return head;
}
int insertHead(Node* L,ElemType e)
{
    Node *p=new Node;
    p->data=e;
    p->prev=L;
    p->next=L->next;
    if(L->next!=nullptr)
    {
        L->next->prev=p;
    }
    L->next=p;
    return 1;
}
Node* insertTail(Node *tail,ElemType e)
{
    Node *p=new Node;
    p->data=e;
    p->prev=tail;
    tail->next=p;
    p->next=nullptr;
    return p;
}
int insertNode(Node *L,int pos,ElemType e)
{
    Node *p=L;
    int i=0;
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==nullptr)
        {
            return 0;
        }
    }
    Node *q=new Node;
    q->data=e;
    q->prev=p;
    q->next=p->next;
    p->next->prev=q;
    p->next=q;
    return 1;
}
void freeList(Node*L)
{
    Node *p=L->next;
    Node *q;  
    while(p!=nullptr)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=nullptr;
} 
int deleteNode(Node*L,int pos)
{
    Node*p=L;
    int i=0;
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==nullptr)
        {
            return 0;
        }
    }
    if(p->next==nullptr)
    {
        cout<<"要删除位置错误\n";
        return 0;
    }
    Node *q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
    return 1;
}
void listNode(Node* L)
{
    Node *p=L->next;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
Node* get_tail(Node *L)
{
    Node *p=L;
    while(p->next!=nullptr)
    {
        p=p->next;
    }
    return p;
}
int main()
{
    Node *list=initList();
    insertHead(list,30);
    insertHead(list,20);
    insertHead(list,10);
    listNode(list);
    Node *tail=get_tail(list);
    tail=insertTail(tail,40);
    tail=insertTail(tail,50);
    tail=insertTail(tail,60);
    listNode(list);
    insertNode(list,2,15);
    listNode(list);
    deleteNode(list,2);
    listNode(list);
    return 0;
}