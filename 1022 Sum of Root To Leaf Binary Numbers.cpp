// 2026/02/25 10:05:01
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), [](int a, int b){ // don't use const and reference small types
            int aSetBits = __builtin_popcount(a);
            int bSetBits = __builtin_popcount(b);

            if(aSetBits == bSetBits)
                return a < b;

            return (aSetBits < bSetBits);
        });

        return arr;
    }

void soln()
{
    vector<vector<int>> testSet{
        {0,1,2,3,4,5,6,7,8},
        {1024,512,256,128,64,32,16,8,4,2,1},
        {1111,7644,1107,6978,8742,1,7403,7694,9193,4401,377,8641,5311,624,3554,6631},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        vector<int> res = sortByBits(testSet[i]);
        printArray(res);
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