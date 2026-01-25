// 2026/01/25 15:50:00

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

bool isSameTree(TreeNode* p, TreeNode* q) {
    
    if(p == nullptr && q == nullptr)
        return true;

    if(p == nullptr || q == nullptr)
        return false;

    if(p->val != q->val)
        return false;
    
    
    bool leftT = isSameTree(p->left, q->left);
    bool rightT = isSameTree(p->right, q->right);
    return leftT & rightT;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL) return p == q;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

void soln()
{
    TreeNode *p, *p11, *p12, *q, *q11, *q12;
    
    p = new TreeNode(1);
    p11 = new TreeNode(2);
    p12 = new TreeNode(3);


    q = new TreeNode(1);
    q11 = new TreeNode(2);
    q12 = new TreeNode(3);

    cout << isSameTree(p, q) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}