// 2026/02/23 15:41:35
// https://leetcode.com/problems/convert-a-number-to-hexadecimal/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

string toHex(int num) {

        unsigned int n = num;
        string s;
        while(n){
            
            int rem = n%16;
            if(rem>9)
                s += ((rem-10) + 'a');
            else
                s += (rem + '0'); 
            n/=16;
        }

        reverse(s.begin(), s.end());
        return s.empty() ? "0" : s;   
    }

void soln()
{
    vector<int> testSet{
        26,-1,INT_MIN, INT_MAX,0
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << toHex(testSet[i])<< endl;
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