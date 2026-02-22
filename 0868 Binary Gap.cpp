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

int binaryGap1(int n) {

        int gap = 0,b1=-1,b2=-1;
        while (n)
        {   
            if(n&1){
                if(b1!=-1){
                    b1 = 1;
                }

            }

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


int binaryGap2(int n) {
    n >>= __builtin_ctz(n);
    if (n == 1) return 0;
    int maxGap = 0, gap = 0;

    while (n) {
        if (n & 1) {
            maxGap = max(maxGap, gap);
            gap = 0;
        } else
            gap++;
        n >>= 1;
    }

    return maxGap + 1;
}

int binaryGap3(unsigned n) {
    int d=0, p=32;
    for(; n>0; n&=(n-1)){
        int ctz=countr_zero(n);
        d=max(d, ctz-p);
        p=ctz;
    }
    return d;
}

int binaryGap4(int n) {
    int start=-1,end=-1;
    int ans=0;

    for(int i=0;i<32;i++){
        int d=(n>>i) & 1;
        if(d){
            start=(start==-1)?i:start;
            end=(end==-1)?start:i;
            ans=max(ans,end-start);
            start=end;
        }
    }

    return ans;
}


int binaryGap5(int n) {   
    int i=0;
    int cnt = 0;
    int idx = 0;
    int gap = 0;
    while(n!=0){
        if((n&1)==1){                
            if(cnt!=0){
                gap = Math.max(gap, i-idx);                    
            }
            idx = i;
            cnt++;
        }
        n=n>>1;
        i++;
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