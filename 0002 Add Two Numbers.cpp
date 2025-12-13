// 2025/12/13 15:53:16

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void traverseLLRec(ListNode *head)
{
    if (head == nullptr)
    {
        cout << endl;
        return;
    }

    cout << head->val;
    if (head->next != NULL)
        cout << "->";
    else
        cout << endl;
    traverseLLRec(head->next);
}

ListNode *insertAtEnd(ListNode *head, int x)
{
    ListNode *node = new ListNode;
    ListNode *temp = head;
    node->val = x;
    node->next = nullptr;

    if (head == nullptr)
    {
        head = node;
        return head;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *l = nullptr;
    int rem = 0;
    while (l1 != nullptr && l2 != nullptr)
    {
        int summation = (l1->val) + (l2->val) + rem;
        int r = summation % 10;
        rem = summation / 10;

        l1 = l1->next;
        l2 = l2->next;

        l = insertAtEnd(l, r);
    }

    while (l1 != nullptr)
    {
        int summation = (l1->val) + rem;
        int r = summation % 10;
        rem = summation / 10;

        l1 = l1->next;
        l = insertAtEnd(l, r);
    }

    while (l2 != nullptr)
    {
        int summation = (l2->val) + rem;
        int r = summation % 10;
        rem = summation / 10;

        l2 = l2->next;
        l = insertAtEnd(l, r);
    }

    if (rem)
        l = insertAtEnd(l, rem);

    return l;
}

void traverseLL(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
void soln()
{
    ListNode *head = new ListNode;
    ListNode *l1 = new ListNode;
    ListNode *l2 = new ListNode;
    ListNode *n11 = new ListNode;
    ListNode *n12 = new ListNode;
    ListNode *n13 = new ListNode;
    ListNode *n14 = new ListNode;
    ListNode *n15 = new ListNode;
    ListNode *n16 = new ListNode;
    ListNode *n17 = new ListNode;

    ListNode *n21 = new ListNode;
    ListNode *n22 = new ListNode;
    ListNode *n23 = new ListNode;
    ListNode *n24 = new ListNode;

    l1 = n11;
    l2 = n21;

    n11->val = 9;
    n11->next = n12;

    n12->val = 9;
    n12->next = n13;

    n13->val = 9;
    n13->next = n14;

    n14->val = 9;
    n14->next = n15;

    n15->val = 9;
    n15->next = n16;

    n16->val = 9;
    n16->next = n17;

    n17->val = 9;
    n17->next = nullptr;

    traverseLLRec(l1);
    // traverseLL(l1);

    l2 = n21;

    n21->val = 9;
    n21->next = n22;

    n22->val = 9;
    n22->next = n23;

    n23->val = 9;
    n23->next = n24;

    n24->val = 9;
    n24->next = nullptr;

    // traverseLL(l2);
    traverseLLRec(l2);

    head = addTwoNumbers(l1, l2);
    traverseLLRec(head);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}