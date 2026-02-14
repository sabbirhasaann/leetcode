// 2026/02/14 08:10:19
// https://leetcode.com/problems/champagne-tower/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void generator();
double t[101][101]; 

double champagneTower(int poured, int query_row, int query_glass) {
    
    vector<vector<double>> tower(query_row+1, vector<double>(query_row+1, 0));
    
    tower[0][0] = (double)poured;    
    for(int i=0;i<query_row;++i){
        for(int j=0;j<=i;++j){
            double overflow = (tower[i][j] - 1) / 2.0;
            if(overflow>0){
                tower[i+1][j] += overflow;
                tower[i+1][j+1] += overflow;
            }
        }
    }

    return min(1.0, tower[query_row][query_glass]);    
}

double solve(int poured, int row, int glass)
{
    
    if(row < 0 || glass > row || glass < 0)
    {
        return 0.00;
    }
    
    
    if(row == 0 && glass == 0)
    {
        return poured;
    }
    
    
    if(t[row][glass] > -1)
    {
        return t[row][glass];
    }
    
    
    double left = (solve(poured, row - 1, glass - 1) - 1) / 2;
    
    
    if(left < 0)
    {
        left = 0;
    }
    
    double right = (solve(poured, row - 1, glass) - 1) / 2;
    
    
    if(right < 0)
    {
        right = 0;
    }
    double total = left + right;
    
    return t[row][glass] = total;
    
    
}
double champagneTower1(int poured, int query_row, int query_glass) {
    memset(t, -1, sizeof(t));
    return min(1.00, solve(poured, query_row, query_glass));
}

double champagneTower2(int poured, int query_row, int query_glass) {
    vector<double>dp(query_row+2,0.0);
    dp[0]=poured;
    for(int i=1;i<=query_row;i++){
        for(int j=i;j>=0;j--){
            dp[j+1] += dp[j] = max((dp[j]-1)/2,0.0);
        }
    }
    return min(dp[query_glass],1.0);
}

void soln()
{

    // generator();
    int poured = 1, query_row = 1, query_glass = 1;
    cout << champagneTower(poured, query_row, query_glass) << endl;

    poured = 2, query_row = 1, query_glass = 1;
    cout << champagneTower(poured, query_row, query_glass) << endl;

    poured = 100000009, query_row = 33, query_glass = 17;
    cout << champagneTower(poured, query_row, query_glass) << endl;

}

void generator(){
    int n = 10, poured = 5;
    vector<vector<double>> mat(n+1, vector<double>(n+1, 0));
    
    mat[0][0] = (double)poured;    
    for(int i=0;i<10;++i){
        for(int j=0;j<=i;++j){
            double overflow = (mat[i][j] - 1) / 2.0;
            if(overflow>0){
                mat[i+1][j] += overflow;
                mat[i+1][j+1] += overflow;
            }
        }
        
    }

    for(int r = 0;r<=n;++r)
    {
        for(int c = 0; c<=r;++c)
            cout << mat[r][c] << " ";
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