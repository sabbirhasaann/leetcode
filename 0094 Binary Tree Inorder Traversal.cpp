// 2026/03/28 21:47:05
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

void traversal(TreeNode* root, vector<int> &r){
        if(root==nullptr)
            return;
        traversal(root->left, r);
        r.push_back(root->val);
        traversal(root->right, r);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        traversal(root, r);
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