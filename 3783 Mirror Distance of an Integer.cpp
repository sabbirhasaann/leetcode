// 2026/04/18 08:05:13
// https://leetcode.com/problems/mirror-distance-of-an-integer/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

long long reverse(int x) {
    
    long long rev = 0;
    while (x != 0) {
        int digit = x % 10;
        rev = rev * 10 + digit;
        x /= 10;
    }

    return rev;        
}

int mirrorDistance(int n) {
        long long rn = reverse(n);
        return abs(rn-n);
    }


int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int x = stoi(s);
        return (abs(x-n));
    }
    
void soln()
{
    vector<int> testSet{
        25,10,7
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << mirrorDistance(testSet[i])<< endl;
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