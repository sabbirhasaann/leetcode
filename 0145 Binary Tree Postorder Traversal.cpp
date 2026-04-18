// 2026/04/18 08:25:15
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'
#define null INT_MIN

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

TreeNode* buildBinTree(vector<int> &nodes){
    if(nodes.empty() || nodes[0]==null)
        return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i<nodes.size()){
        TreeNode* curr = q.front();
        q.pop();

        if(i<nodes.size() && nodes[i]!=null){
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        ++i;

        if(i<nodes.size() && nodes[i] != null){
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        ++i;
    }
    return root;
}

void traverse(TreeNode *root, vector<int> &res){
    if(root == nullptr)
        return;
    traverse(root->left, res);
    traverse(root->right, res);
    res.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void soln()
{
    vector<vector<int>> testSet{
        {1, null, 2, 3},
        {1, 2, 3, 4, 5, null, 8, null, null, 6, 7, 9},
        {},
        {1}
    };
    for(int i=0;i<testSet.size();++i){
        TreeNode* root = buildBinTree(testSet[i]);
        auto start = high_resolution_clock::now();
        vector<int> res = postorderTraversal(root);
        printArray(res);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " * 10^-6 microseconds" << endl;
        deleteTree(root);
    }
}


int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}