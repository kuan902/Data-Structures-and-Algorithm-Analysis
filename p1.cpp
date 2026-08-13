#include<iostream>
/*#include<cstdlib>
#include<cstring>
using namespace std;
struct book
{
    int isdn;
    char BookName[20];
    double price;
};
struct hero
{
    char name[5];
    int life;
    int attack;
    double magic;
};
int main()
{
    book b;
    b.isdn=1232390;
    strcpy(b.BookName,"JavaScript");
    b.price=100;
    cout<<b.isdn<<" "<<b.BookName<<" "<<b.price<<endl;
    return 0;
}*/

#include<iostream>
#include<cstdlib>
using ElemType=int;
using namespace std;
const int MAXSIZE=100;
struct SeqList
{
    ElemType *data;
    int length;
};
SeqList* initList()
{
    SeqList *L=(SeqList*)malloc(sizeof(SeqList));
    L->data=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    L->length=0;
    return L;
}
/*void initList(SeqList *L)
{
    L->length=0;
}*/
int appendElem(SeqList *L,ElemType e)
{
    if(L->length>=MAXSIZE)
    {
        cout<<"顺序表已满"<<endl;
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
    return 1;
}
void listElem(SeqList *L)
{
    for(int i=0;i<L->length;i++)
    {
        cout<<L->data[i]<<" ";
    }
    cout<<endl;
    cout<<L->length<<endl;
}
int insertElem(SeqList *L,int pos,ElemType e)
{
    if(L->length>=MAXSIZE)
    {
        cout<<"表已经满了"<<endl;
        return 0;
    }
    if(pos<1||pos>L->length)
    {
        cout<<"插入位置错误\n";
        return 0;
    }
    if(pos<=L->length)
    {
        for(int i=L->length;i>=pos-1;i--)
        {
            L->data[i+1]=L->data[i];
        }
        L->data[pos-1]=e;
        L->length++;
    }
    return 1;
}
int deleteElem(SeqList *L,int pos,ElemType *e)
{
    if(L->length==0)
    {
        cout<<"空表\n";
        return 0;
    }
    if(pos<1||pos>L->length)
    {
        cout<<"删除数据位置有误\n";
        return 0;
    }
    *e=L->data[pos-1];
    if(pos<L->length)
    {
          for(int i=pos;i<L->length;i++)
          {
            L->data[i-1]=L->data[i];
          }
    }
    L->length--;
    return 1;
}
int findElem(SeqList *L,ElemType e)
{
    if(L->length==0)
    {
        cout<<"空列表\n";
        return 0;
    }
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]==e)
        {
            return i+1;
        }
    }
    return 0;
}
int main()
{
    SeqList *list=initList();       //声明一个指针，去堆内存中创建
    cout<<"初始化成功，目前长度为"<<list->length<<endl;
    cout<<"目前占用内存为"<<sizeof(list->data)<<"字节"<<endl;
    appendElem(list,88);        //list已经成为指针可直接传
    appendElem(list,45);
    appendElem(list,43);
    appendElem(list,17);
    appendElem(list,23);
    listElem(list);
    insertElem(list,1,18);
    listElem(list);
    ElemType delData;
    deleteElem(list,2,&delData);
    cout<<"被删除的数据为："<<delData<<endl;
    listElem(list);
    cout<<findElem(list,43)<<endl;
    return 0;
}