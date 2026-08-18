#include<iostream>
using namespace std;
const int MAXSIZE=100;
using ElemType=int;
struct Queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};
void initQueue(Queue *Q)
{
    Q->front=0;
    Q->rear=0;
    
}