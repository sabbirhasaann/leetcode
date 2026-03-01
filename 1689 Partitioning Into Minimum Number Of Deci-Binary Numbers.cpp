// 2026/03/01 09:51:12
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

int minPartitions(string n) {
        int maxDigit=0;
        for(char c: n){
            int d = c - '0';
            if(d > maxDigit)
                maxDigit = d;
        }
        return maxDigit;
    }

void soln()
{
    vector<string> testSet{
        "32",
        "82734",
        "27346209830709182346",
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << minPartitions(testSet[i])<< endl;
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