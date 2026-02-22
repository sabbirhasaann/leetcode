// 2026/02/22 20:06:35
// https://leetcode.com/problems/binary-gap/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int binaryGap(int n) {

        int gap = 0;
        string s;
        while (n)
        {   
            if(n&1)
                s+='1';
            else
                s+='0';

            n>>=1;
        }
        
        int len = s.size();
        int k = 0;
        for(int i=0;i<len;++i){
            if(s[i]=='1'){
                if(s[k]=='1'){
                    gap = max(gap, i-k);
                }
                k = i;
            }
        }
    
        return gap;
        
}

void soln()
{
    vector<int> testSet{
        22,8,5,1000000000
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << binaryGap(testSet[i])<< endl;
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