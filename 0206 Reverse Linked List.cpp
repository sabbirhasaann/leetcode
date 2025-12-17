// 2025/12/17 21:28:38

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

ListNode *reverseList(ListNode *head)
{

    if (head == nullptr)
        return nullptr;

    ListNode *temp = nullptr;

    while (head != nullptr)
    {
        ListNode *newNode = new ListNode(head->val);
        newNode->next = temp;
        temp = newNode;
        head = head->next;
    }

    return temp;
}

void soln()
{
    // head = [1,2,3,4,5]
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head = reverseList(head);
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}