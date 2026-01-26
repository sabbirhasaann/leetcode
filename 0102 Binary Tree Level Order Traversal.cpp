// 2026/01/26 02:40:26

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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;        

    queue<TreeNode*> q;
    if(root!=nullptr){
        q.push(root);
    }

    while(!q.empty()){
        
        int levelSize = q.size();
        vector<int> v;
        for(int i=0;i<levelSize;i++){
            TreeNode *current = q.front();
            q.pop();
            v.push_back(current->val);

            if(current->left != nullptr)
                q.push(current->left);
            if(current->right != nullptr)
                q.push(current->right);
        }
        res.push_back(v);

    }

    return res;
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

    vector<vector<int>> res = levelOrder(root);

    for(vector<int> v: res)
    {
        for(int x: v)
            cout << x <<" ";
        cout << endl;
    }
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}