#include <iostream>
using namespace std;

// 定义链表结点结构
typedef struct LNode {
    int data;
    struct LNode *link;
} LNode, *LinkList;

/**
 * @param list 带头结点的链表头指针
 * @param k 倒数第k个位置，k为正整数
 * @return 成功返回1，输出对应节点data；失败返回0
 */
int findLastK(LinkList list, int k)
{
    // k非法（非正数）直接返回0
    if (k <= 0)
        return 0;

    LNode *fast = list;
    LNode *slow = list;

    // 快指针先向前走k步
    for (int i = 0; i < k; i++)
    {
        fast = fast->link;
        // 如果走k步过程中fast为空，代表链表有效节点不足k个
        if (fast == nullptr)
        {
            return 0;
        }
    }

    // 快慢指针同步前进，直到fast走到NULL
    while (fast != nullptr)
    {
        fast = fast->link;
        slow = slow->link;
    }

    // slow此时指向倒数第k个结点
    cout << slow->data << endl;
    return 1;
}

// 主函数：测试用例：链表：头结点 →1 →2 →3 →4 →5
int main()
{
    // 创建头结点
    LinkList L = new LNode();
    L->link = nullptr;

    int arr[] = {1, 2, 3, 4, 5};
    LNode *p = L;
    // 尾插法构建链表
    for (int x : arr)
    {
        LNode *newNode = new LNode();
        newNode->data = x;
        newNode->link = nullptr;
        p->link = newNode;
        p = newNode;
    }

    // 测试：查找倒数第2个，预期输出4，返回1
    int res = findLastK(L, 2);
    cout << "返回值：" << res << endl;
  
    return 0;
}
