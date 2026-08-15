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
    return 1;
}
Node* get_tail(Node*L)
{
    Node *p=L;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    return p;
}
Node* insertTail(Node*tail,ElemType e)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    tail->next=p;
    p->next=NULL;
    return p;
}
int insertNode(Node*L,int pos,ElemType e)
{
    //用来保存插入位置的前驱节点
    Node *p=L;
    int i=0;
    //遍历链表找到插入位置的前驱节点
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        }
    }
    //要插入的新节点
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}
int deleteNode(Node*L,int pos)
{
    //要删除节点的前驱
    Node*p=L;
    int i=0;
    //遍历链表，找到要删除节点的前驱
    while(i<pos-1)
    {
        p=p->next;
        i++;
        if(p==NULL)
        {
            return 0;
        } 
    }
    if(p->next==NULL)
    {
        cout<<"要删除的位置错误\n";
        return 0;
    }
    //q指向要删除的节点
    Node *q=p->next;
    //让要删除节点的前驱指向要删除节点的后继
    p->next=q->next;
    //释放要删除节点的内存空间
    free(q);
    return 1;
}
int listlength(Node *L)
{
    Node*p=L;
    int len=0;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}
void freeList(Node *L)
{
    Node *p=L->next;
    Node *q;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}
void listNode(Node*L)
{
    Node *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    Node *list=initList();
    insertHead(list,10);
    insertHead(list,20);
    insertHead(list,30);
    Node *tail=get_tail(list);
    tail=insertTail(tail,40);
    tail=insertTail(tail,50);
    tail=insertTail(tail,60);
    listNode(list);
    insertNode(list,2,25);
    listNode(list);
    deleteNode(list,2);
    listNode(list);
    cout<<listlength(list)<<endl;
    freeList(list);
    cout<<listlength(list)<<endl;
    return 0;
}
