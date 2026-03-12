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


int findJudge1(int n, vector<vector<int>>& trust) {
         vector<int> count(n + 1, 0);
        for (auto& t : trust)
            count[t[0]]--, count[t[1]]++;

        for (int i = 1; i <= n; ++i) {
            if (count[i] == n - 1) return i;
        }

        return -1;
    }

int findJudge2(int n, vector<vector<int>>& trust) 
    {
        vector<int> nodes(n+1,n-1),visited(n+1,0);
        for(int i=0;i<trust.size();++i)
        {
            nodes[trust[i][0]]++;
            nodes[trust[i][1]]--;
        }
        for(int i=1;i<=n;++i)
        {
            if(nodes[i]==0)
            {
                return i;
            };
        }
        return -1;
    }

int main(){
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}