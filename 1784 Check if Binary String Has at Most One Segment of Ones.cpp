// 2026/03/06 10:59:50
// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

bool checkOnesSegment(string s) {
        for(int i=0;i<s.length()-1;++i)
            if(s[i]=='0' && s[i+1]=='1')
                return false;
        return true;
    }

void soln()
{
    vector<string> testSet{
        "110",
        "1001"
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << checkOnesSegment(testSet[i])<< endl;
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