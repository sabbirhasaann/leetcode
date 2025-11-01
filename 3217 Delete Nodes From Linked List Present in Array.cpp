#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());

        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *curr = temp;

        while (curr->next)
        {
            if (numSet.count(curr->next->val))
                curr->next = curr->next->next;

            else
                curr = curr->next;
        }

        return temp->next;
    }

    // efficient solution 1
    ListNode *modifiedList1(vector<int> &nums, ListNode *head)
    {
        bitset<100001> map;
        for (int i = 0, n = nums.size(); i < n; ++i)
            map.set(nums[i]);
        while (head && map.test(head->val))
            head = head->next;
        ListNode *curr = head;
        while (curr && curr->next)
        {
            if (map.test(curr->next->val))
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }

    // Efficient Solution 2
    ListNode *modifiedList2(vector<int> &nums, ListNode *head)
    {
        int max = -1;
        for (int num : nums)
            max = num > max ? num : max;

        vector<bool> freq(max + 1, false);

        for (int num : nums)
            freq[num] = true;

        ListNode *temp = new ListNode();
        ListNode *current = temp;

        while (head != nullptr)
        {
            if (head->val >= freq.size() || !freq[head->val])
            {
                current->next = head;
                current = current->next;
            }
            head = head->next;
        }

        current->next = nullptr;

        return temp->next;
    }

    // Memory Efficient Solution 1 - 3
    bool check(vector<int> &nums, int s, int e, int value)
    {
        if (s > e)
        {
            return false;
        }
        int mid = (s + e) / 2;
        if (nums[mid] == value)
        {
            return true;
        }
        else if (nums[mid] < value)
        {
            return check(nums, mid + 1, e, value);
        }
        else
        {
            return check(nums, s, mid - 1, value);
        }
        // return left || right;
    }
    ListNode *modifiedList3(vector<int> &nums, ListNode *head)
    {
        ListNode *temp = head;
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size() - 1;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            int mid = (s + e) / 2;
            int value = temp->val;
            // cout<<check(nums,s,e,value);
            if (check(nums, s, e, value))
            {
                if (prev == NULL)
                {
                    ListNode *h = temp;
                    temp = temp->next;
                    h->next = NULL;
                    head = temp;
                }
                else
                {
                    prev->next = temp->next;
                    temp->next = NULL;
                    temp = prev->next;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }

    // Memory Efficient Solution 2 - 4
    ListNode *modifiedList4(vector<int> &nums, ListNode *head)
    {
        sort(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy;
        while (curr->next)
        {
            if (binarySearch(nums, curr->next->val))
            {
                ListNode *delNode = curr->next;
                curr->next = delNode->next;
                // delete delNode;
            }
            else
            {
                curr = curr->next;
            }
        }
        ListNode *newHead = dummy->next;
        // delete dummy;
        return newHead;
    }
    bool binarySearch(vector<int> &nums, int val)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == val)
            {
                return true;
            }
            else if (nums[mid] > val)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }

    // Memory Efficient Solution 5
    ListNode *modifiedList5(vector<int> &nums, ListNode *head) // 3217
    {
        unordered_multiset<int> s(nums.begin(), nums.end());
        if (head == nullptr)
        {
            return head;
        }
        while (s.find(head->val) != s.end())
        {
            head = head->next;
        }
        ListNode *p = head;
        if (head == nullptr)
        {
            return nullptr;
        }
        while (p->next != nullptr)
        {
            if (s.find(p->next->val) != s.end())
            {
                ListNode *tam = p->next;
                p->next = tam->next;
                delete tam;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};

int main()
{
    vector<int> nums;
    nums = {1, 2, 3};

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    ListNode *res = solution.modifiedList(nums, head);

    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}