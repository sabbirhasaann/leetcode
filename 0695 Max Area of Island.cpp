// 2026/01/27 09:36:34

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int bfs(int i,int j, vector<vector<int>> &grid){
    int m = grid.size(), n = grid[0].size(), area = 0;
    vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j] = 0;

    while(!q.empty()){
        pair<int,int> idx = q.front();
        q.pop();
        ++area;

        for(auto d: dirs){
            int r = idx.first + d.first;
            int c = idx.second + d.second;

            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
            {
                q.push({r,c});
                grid[r][c] = 0;

            }
        }
    }
    return area;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int maxArea = 0;
    

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1)
            maxArea = max(maxArea,bfs(i,j,grid));
        }
    }
    return maxArea;
}

void soln()
{
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    cout << maxAreaOfIsland(grid)<< endl;

    grid = {
        {0,0,0,0,0,0,0,0}
    };
    cout << maxAreaOfIsland(grid) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}