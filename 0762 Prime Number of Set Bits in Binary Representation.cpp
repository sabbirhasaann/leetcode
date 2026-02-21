// 2026/02/21 14:10:00
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'
#define MAX 1e6

vector<bool> prime(MAX+1,true);
void primes(){

    prime[0] = prime[1] = false;
    for(int i=2;i<=MAX;i++)
    {
        if(prime[i] && ((long long)i*i <= MAX))
        {
            for(int j=i*i;j<=MAX;j+=i)
                prime[j]= false;
        }
    }

}

int countPrimeSetBits(int left, int right) {
    int cnt = 0;    
    while (left<=right)
    {
        int setBits = __builtin_popcount(left);
        if(prime[setBits])
            ++cnt;
        ++left;
    }
    return cnt;
}


void soln()
{
    // primes();
    vector<pair<int,int>> testSet{
        {6,10},
        {10,15},
        {0,1000000} 
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << countPrimeSetBits(testSet[i].first, testSet[i].second)<< endl;
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