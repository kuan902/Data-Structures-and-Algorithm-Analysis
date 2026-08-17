#include <iostream>
using namespace std;
struct LNode
{
    char data;
    LNode* next;
};
using LinkList=LNode*;

int getLength(LinkList L) {
    int len = 0;
    LinkList p = L->next;
    while (p != nullptr) {
        len++;
        p = p->next;
    }
    return len;
}

LNode* findCommonSuffix(LinkList str1, LinkList str2) {
    int len1 = getLength(str1);
    int len2 = getLength(str2);
    LinkList p = str1->next;
    LinkList q = str2->next;

    if (len1 > len2) {
        int d = len1 - len2;
        while (d--) p = p->next;
    } else {
        int d = len2 - len1;
        while (d--) q = q->next;
    }

    while (p != nullptr && q != nullptr && p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}

int main() {
    LNode* i_node = new LNode{'i', nullptr};
    LNode* n_node = new LNode{'n', nullptr};
    LNode* g_node = new LNode{'g', nullptr};
    i_node->next = n_node;
    n_node->next = g_node;

    // str1: head -> l -> o -> a -> d -> i_node
    LinkList str1 = new LNode;
    str1->next = new LNode{'l',
        new LNode{'o',
            new LNode{'a',
                new LNode{'d', i_node}
            }
        }
    };

    // str2: head -> b -> e -> i_node
    LinkList str2 = new LNode;
    str2->next = new LNode{'b',
        new LNode{'e', i_node}
    };

    LNode* res = findCommonSuffix(str1, str2);
    if (res != nullptr) {
        cout << "共同后缀起始结点data = " << res->data << endl;
    } else {
        cout << "无公共后缀" << endl;
    }
    return 0;
}