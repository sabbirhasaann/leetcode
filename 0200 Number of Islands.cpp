// 2026/01/27 07:02:49

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int isLands = 0;

    vector<vector<bool>> visited(n, (vector<bool>(m, false)));
    queue<pair<int,int>> q;
    vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j] == '1'){
                q.push({i,j});
                visited[i][j] = true;

                while (!q.empty())
                {
                    pair<int,int> idx = q.front();
                    q.pop();

                    for(auto d: dir){
                        int r = idx.first + d.first;
                        int c = idx.second + d.second;

                        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && !visited[r][c]){
                            visited[r][c] = true;
                            q.push({r,c});
                        }
                    }
                }
                ++isLands;
                
            }
        }
    }
    return isLands;

}

void soln()
{
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    cout << numIslands(grid) << endl;

    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << numIslands(grid) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}