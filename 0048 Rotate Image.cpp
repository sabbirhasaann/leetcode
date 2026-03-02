// 2026/03/02 08:04:41
// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j <=i ; j++)
                swap(matrix[i][j], matrix[j][i]);
                
        for(int i=0;i<n;++i)
            for(int l=0,r=n-1;l<=r;++l,--r)
                swap(matrix[i][l], matrix[i][r]);
        
        // for(int i=0; i<n; i++){
        //     reverse(matrix[i].begin(),matrix[i].end());
        // }
    }

void print_matrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " " ;
        cout << endl;
    }
}
void soln()
{
    vector<vector<vector<int>>> testSet{
        {{1,2,3},
        {4,5,6},
        {7,8,9}},
        {{5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}}
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        rotate(testSet[i]);
        print_matrix(testSet[i]);
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