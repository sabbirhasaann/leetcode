// 2026/02/12 11:07:26
// https://leetcode.com/problems/longest-balanced-substring-i/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int longestBalanced(string s) {
    unordered_map<char, int> freq;
    
    int max_ans = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        freq.clear();

        for (int j = i; j < n; j++) {

            freq[s[j]]++;
            auto p1 = freq.begin();

            bool flag = true;

            for(pair<char,int> p: freq)
            {
                if(p.second != p1->second)
                {
                    flag = false;
                    break;
                }

            }
            if(flag)
                max_ans = max(max_ans , j - i + 1) ;
        }

    }
    return max_ans ;
}
void soln()
{
    string s="abbac";
    cout << longestBalanced(s) << endl;

    s = "zzabccy";
    cout << longestBalanced(s) << endl;

    s ="aba";
    cout << longestBalanced(s) << endl;

    s ="aaaaaa";
    cout << longestBalanced(s) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}