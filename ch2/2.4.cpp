#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

bool PArtit(Node *node)
{
    if (node == NULL || node->next == NULL)
    {
        return false;
    }
    node->val = node->next->val;
    node->next = node->next->next;
    return true;
}

int main()
{
    Node *test1 = new Node();
    Node *test2 = new Node();
    Node *test3 = new Node();
    Node *test4 = new Node();
    Node *test5 = new Node();
    test1->val = 7;
    test2->val = 4;
    test3->val = 8;
    test4->val = 9;
    test5->val = 11;
    test1->next = test2;
    test2->next = test3;
    test3->next = test4;
    test4->next = test5;
    test5->next = NULL;

    removeMiddle(test1);
    return 0;
}