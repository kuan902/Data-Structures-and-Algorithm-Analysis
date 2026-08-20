#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXSIZE=100;
using ElemType=int;
struct Stack
{
    ElemType *data;
    int top;
};
enum contentType
{
    LEFT_PARE,RIGHT_PARE,ADD,
    SUB,MUL,DIV,MOD,EOS,NUM
};  
char expr[]="82/2+56*-";

//初始化
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
    *e=s->data[s->top];
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
contentType getToken(char *symbol,int *index)
{
    *symbol=expr[*index];
    *index=*index+1;
    switch(*symbol)
    {
        case '(':
            return LEFT_PARE;
        case ')':
            return RIGHT_PARE;
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '%':
            return MOD;
        case '\0':
            return EOS;
        default: 
            return NUM;
    }
}

int eval(Stack *s)
{
    char symbol;
    int op1,op2;
    int index=0;
    contentType token;
    token=getToken(&symbol,&index);
    ElemType result;
    while(token !=EOS)
    {
        if(token ==NUM)
        {
            push(s,symbol-'0');
        }
        else
        {
            pop(s,&op2);
            pop(s,&op1);
            switch(token)
            {
                case ADD:
                    push(s,op1+op2);
                    break;
                case SUB:
                    push(s,op1-op2);
                    break;
                case MUL:
                    push(s,op1*op2);
                    break;
                case DIV:
                    push(s,op1/op2);
                    break;
                case MOD:
                    push(s,op1%op2);
                    break;
                default:
                    break;
            }
        }
        token=getToken(&symbol,&index);
    }
    pop(s,&result);
    cout<<result<<endl;
    return 1;
}
int main()
{
    Stack *s=initStack();
    eval(s);
    return 0;
}