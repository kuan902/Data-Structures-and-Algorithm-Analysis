#include<iostream>
using namespace std;
using ElemType=int;
//结点结构体，链表里面每一个小节点
struct QueueNode
{
    ElemType data;      //存真正的数据
    QueueNode *next;    //指向下一个节点的指针
};
//队列管理结构体，保存队头、队尾两个指针
struct Queue
{
    QueueNode *front;   // 队头指针，指向第一个有效节点
    QueueNode *rear;    // 队尾指针，指向最后一个有效节点
};
//初始化
Queue* initQueue()
{
    Queue *q=new Queue;     //创建队列管理结构体
    QueueNode* node=new QueueNode;      //创建头节点
    node->data=0;       //头节点data随便赋值
    node->next=nullptr;
    q->front=node;      //front、rear都指向头节点
    q->rear=node;
    return q;
}
//判断队列是否为空
int isEmpty(Queue *q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void equeue(Queue *q,ElemType e)
{
    //申请一块内存，创建新节点
    QueueNode *node=new QueueNode;
    node->data=e;       //入队数据e存入新节点
    node->next=nullptr;     //尾插法新节点后面接nullptr
    q->rear->next=node;     //原来头节点的next，指向新节点
    q->rear=node;       //把rear指针移动，更新到新的尾巴
}
//出队
int dequeue(Queue *q,ElemType *e)
{
    //node 拿到第一个真实数据结点（跳过头结点）
    QueueNode *node=q->front->next;
    *e=node->data;      //把出队元素的值带回调用者
    q->front->next=node->next;  // 头结点跳过要删掉的node，重新接链子
    //特殊判断：如果删掉的这个node，正好就是队尾结点（代表删完队列最后一个元素）
    if(q->rear==node)
    {
        q->rear=q->front;   // rear退回到头结点！恢复空队列状态
    }
    free(node);     //释放被删除节点
    return 1;
}
ElemType getFront(Queue *q)
{
    if(isEmpty(q))
    {
        cout<<"空的\n";
        return 0;
    }
    return q->front->next->data;
}