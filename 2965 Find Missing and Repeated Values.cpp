// 2025/12/10 05:31:06

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid) {
        int num=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                num^=grid[i][j];
            }
        }
        for(int i=1;i<=grid.size()*grid.size();i++){
            num^=i;
        }
        int bit=0;
        while(true){
            int y=1<<bit;
            if((num & y)!=0)break;
            bit++;
        }
        int one=0;
        int zero=0;
        int y=1<<bit;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if((grid[i][j] & y)!=0)one^=grid[i][j];
                else zero^=grid[i][j];
            }
        }
        for(int i=1;i<=grid.size()*grid.size();i++){
            if((i & y)!=0)one^=i;
            else zero^=i;
        }
        bool p=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(one==grid[i][j]){
                    p=true;
                    break;
                }
            }
        }
        if(p)return {one,zero};
        else return {zero,one};
}
vector<int> findMissingAndRepeatedValues1(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n*n;
        vector<int> ans(2, 0);
        vector<int> nums(size+1, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                nums[grid[i][j]]++;
            }
        }

        for(int i = 1; i <= size; ++i){
            if(nums[i] == 2) ans[0] = i;
            if(nums[i] == 0) ans[1] = i;
        }
        return ans;
}

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    int n = grid.size();
    int sum_1_n_n = (n * n) * (n * n + 1) / 2;
    int currentSum = 0;
    map<int, int> cnt;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cnt.find(grid[i][j]) != cnt.end())
            {
                result.push_back(grid[i][j]);
                continue;
            }
            currentSum += grid[i][j];
            cnt[grid[i][j]]++;
        }
    }

    result.push_back(sum_1_n_n - currentSum);
    return result;
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    printArray(findMissingAndRepeatedValues(grid));

    grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    printArray(findMissingAndRepeatedValues(grid));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}