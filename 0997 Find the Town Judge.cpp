// 2026/03/12 20:07:45
// https://leetcode.com/problems/find-the-town-judge/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1, 0),out(n+1,0);

        for(auto v: trust){
            ++in[v[1]];
            ++out[v[0]];
        }   
        for(int i=1;i<=n;++i)
            if(in[i]== n-1 && out[i]==0)
                return i;

        return -1;
    }

void soln()
{
    vector<pair<int, vector<vector<int>>>> testSet{
        {2, {{1,2}}},
        {3, {{1,3},{2,3}}},
        {3, {{1,3},{2,3},{3,1}}},       
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << findJudge(testSet[i].first, testSet[i].second)<< endl;
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