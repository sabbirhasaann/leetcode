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

// last 
bool func(string s)
{
    int cnt=0;
    int c=0;
    for(auto it:s)
    {
        if(it=='1')
        {
            c++;
        }
    }
    for(int i=1;i<=c;i++)
    {
        if(c%i==0) cnt++;
    }
    if(cnt==2) return true;
    return false;
}
int countPrimeSetBits1(int left, int right) {
    int count=0;
    for(int i=left;i<=right;i++)
    {
        string bin="";
        int n=i;
        while(n>0)
        {
            bin+=(n%2)+'0';
            n/=2;
        }
        if(func(bin))
        {
            count++;
        }
    }
    return count;
}

bool isPrime(int bit  ){
    if(bit  < 2 )
         return false ;
    for (int j = 2 ; j < bit  ; j++){
        if(bit  % j == 0)
        return false ;
    }
    return true ;
}
int countPrimeSetBits2(int left, int right) {
    int count =  0 ;
    for(int i = left ; i <= right ;  i++){
    int temp  = i ;
        int bit = 0 ;
        while(temp != 0 ){
        bit += (temp & 1) ;
        temp >>= 1;
        }
        if (isPrime(bit)){
        count ++ ;
        }
    }
    return count ;
}

bool isPrime1(int n){
    if(n==1){
        return false;
    }
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int countPrimeSetBits3(int left, int right) {
    int ans = 0;
    for(int i = left;i<=right;i++){
        if(isPrime1(__builtin_popcount(i))){
            ans++;
        }
    }
    return ans;
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