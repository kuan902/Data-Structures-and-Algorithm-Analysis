#include<iostream>
#include<cstdlib>
using namespace std;
using ElemType=int;
struct Stack
{
    ElemType data;
    Stack *next;
};
//初始化
Stack* initStack()
{
    Stack *s=new Stack;
    s->data=-1;
    s->next=nullptr;
    return s;
}
//判断栈是否为空
int isEmpty(Stack *s)
{
    if(s->next==nullptr)
    {
        cout<<"空的\n";
        return 1;
    }
    else
    {
        return 0;
    }
}
//进栈/压栈
int push(Stack *s,ElemType e)
{
    Stack *p=new Stack;
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}
//出栈
int pop(Stack *s,ElemType *e)
{
    if(s->next==nullptr)
    {
        cout<<"空的\n";
        return 0;
    }
    *e=s->next->data;
    Stack *q=s->next;
    s->next=q->next;
    free(q);
    return 1;
}
//获取栈顶元素
int getTop(Stack *s,ElemType *e)
{
    if(s->next==nullptr)
    {
        cout<<"空的\n";
        return 0;
    }
    *e=s->next->data;
    return 1;
}
int main()
{
    Stack *s=initStack();
    push(s,10);
    push(s,20);
    push(s,30);
    ElemType e;
    pop(s,&e);
    cout<<e<<endl;
    getTop(s,&e);
    cout<<e<<endl;
    return 0;
}