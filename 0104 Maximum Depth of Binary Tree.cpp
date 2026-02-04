// 2026/02/04 10:28:53

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


int maxDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    int leftH = maxDepth(root->left);
    int rightH = maxDepth(root->right);

    return 1 + max(leftH, rightH);
}

void soln()
{
    TreeNode *root, *l1, *r1,*l2, *r2;
    root = new TreeNode(3);

    l1 = new TreeNode(9);

    r1 = new TreeNode(20);
    l2 = new TreeNode(15);
    r2 = new TreeNode(7);

    root->left = l1;
    root->right = r1;

    r1->left = l2;
    r1->right = r2;

    cout << maxDepth(root) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}