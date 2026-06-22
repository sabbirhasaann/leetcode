// 2026/06/22 09:36:22
// https://leetcode.com/problems/middle-of-the-linked-list/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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

ListNode *middleNode(ListNode *head)
{
    ListNode *s = head;
    ListNode *f = head->next;

    while (f && f->next)
    {
        s = s->next;
        f = f->next->next;
    }

    if (f == nullptr)
        return s;
    return s->next;
}

ListNode *insertAtEnd(ListNode *head, int x)
{
    ListNode *newNode = new ListNode(x);
    if (head == nullptr)
        return newNode;
    ListNode *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

void traverseLinkedList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

void soln()
{
    vector<vector<int>> testSet{
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {1},
        {1, 2},
        {1, 2, 3},
        {1, 2, 3, 4},
    };
    for (int i = 0; i < testSet.size(); ++i)
    {
        ListNode *head = nullptr;
        for (int j = 0; j < testSet[i].size(); ++j)
            head = insertAtEnd(head, testSet[i][j]);

        auto start = high_resolution_clock::now();

        head = middleNode(head);
        traverseLinkedList(head);

        delete head;

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}