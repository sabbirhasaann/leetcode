// 2026/06/19 20:27:01
// https://leetcode.com/problems/find-the-highest-altitude/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int largestAltitude(vector<int>& gain) {
        int maxi = 0, sum = 0;
        for(int i=0;i<gain.size();++i){
            sum += gain[i];
            maxi = max(sum, maxi);
        }
        return maxi;
    }

void soln()
{
    vector<vector<int>> testSet{
        {-5,1,5,0,-7},
        {-4,-3,-2,-1,4,3,2},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << largestAltitude(testSet[i])<< endl;
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