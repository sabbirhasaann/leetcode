// 2026/03/26 20:37:16
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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

void traversal(TreeNode* root, vector<int> &r){
    if(root==nullptr)
        return;
    r.push_back(root->val);
    traversal(root->left, r);
    traversal(root->right, r);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> r;
    traversal(root,r);
    return r;
}

void soln()
{
    vector<TreeNode*> testSet{
        
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << (testSet[i])<< endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}