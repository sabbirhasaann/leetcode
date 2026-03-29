// 2026/03/29 22:05:38
// https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

bool canBeEqual(string s1, string s2) {
        if(s1[0]>s1[2])
            swap(s1[0], s1[2]);
        if(s1[1]>s1[3])
            swap(s1[1], s1[3]);
        if(s2[0]>s2[2])
            swap(s2[0], s2[2]);
        if(s2[1]>s2[3])
            swap(s2[1], s2[3]);
        return s1==s2;
    }

bool canBeEqual1(string s1, string s2) {
        for(int i = 0; i < 2; i++){
            if(s1[i] != s2[i]){
                swap(s1[i], s1[i+2]);
            }
        }
        return s1 == s2;
    }

void soln()
{
    vector<pair<string,string>> testSet{
        {"abcd", "cbad"},
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << canBeEqual(testSet[i].first, testSet[i].second)<< endl;
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