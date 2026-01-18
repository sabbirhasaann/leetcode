// 2026/01/18 08:57:45

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* res = new ListNode();
    res = nullptr;
    while (list1 != nullptr && list2 != nullptr)  
    {
        ListNode* node = new ListNode(), *temp = new ListNode();
        temp = res;
        if(list1->val < list2->val)
        {   
            node->val = list1->val;
            list1 = list1->next;   
        }
        else
        {   
            node->val = list2->val;
            list2 = list2->next;   
        }

        if(res == nullptr)
        {
            res = node;
            continue;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        node->next = nullptr;
        temp->next = node;
        
    }

    while (list1 != nullptr)  
    {
        ListNode* node = new ListNode(), *temp = new ListNode();
        temp = res;
    
        node->val = list1->val;
        list1 = list1->next;   
    

        if(res == nullptr)
        {
            res = node;
            continue;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        node->next = nullptr;
        temp->next = node;
        
    }
    
    while (list2 != nullptr)  
    {
        ListNode* node = new ListNode(), *temp = new ListNode();
        temp = res;
    
        node->val = list2->val;
        list2 = list2->next;   
    

        if(res == nullptr)
        {
            res = node;
            continue;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        node->next = nullptr;
        temp->next = node;
        
    }
    
    

    return res;
}

void printNodes(ListNode* head){
    ListNode* temp = new ListNode();
    temp = head;
    while(temp!= nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
void soln()
{
    ListNode* list1,*n11,*n12,*n13;
    ListNode* list2, *n21,*n22,*n23;

    list1 = new ListNode();
    n11 = new ListNode(1);
    n12 = new ListNode(2);
    n13 = new ListNode(4);
    
    list2 = new ListNode();
    n21 = new ListNode(1);
    n22 = new ListNode(3);
    n23 = new ListNode(4);


    list1 = n11;
    n11->next = n12;
    n12->next = n13;
    n13->next = nullptr;

    list2 = n21;
    n21->next = n22;
    n22->next = n23;
    n23->next = nullptr;


    ListNode* res = mergeTwoLists(list1, list2);    
    printNodes(res);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}