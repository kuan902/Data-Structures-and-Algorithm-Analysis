#include<iostream>
const int MAXSIZE=100;
using ElemType=int;
using namespace std;
struct Stack
{
    ElemType *data;
    int top;
};

//初始化
/*void initStack(Stack *s)
{
    s->top=-1;
}
*/
Stack* initStack()
{
    Stack *s=new Stack;
    s->data=new ElemType[MAXSIZE];
    s->top=-1;
    return s;
}
//判断栈是否为空
int isEmpty(Stack *s)
{
    if(s->top==-1)
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
    if(s->top>=MAXSIZE-1)
    {
        cout<<"满了\n";
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}

//出栈
int pop(Stack *s,ElemType *e)
{
    if(s->top==-1)
    {
        cout<<"空的\n";
        return 0;
    }
    *e=s->data[s->top]; //返回出栈元素的值
    s->top--;
    return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e)
{
    if(s->top==-1)
    {
        cout<<"空的\n";
        return 0;
    }
    *e=s->data[s->top];
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