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

bool checkBalanced(vector<int> &freq){
    int a = INT_MAX ;
    for(int i =0;i<26;i++){
        if(freq[i] != 0 ){
            if(a== INT_MAX){
                a= freq[i];
            
            }
            else if(freq[i] != a){
                return false;
            }
        }
    }
    return true;
}
int longestBalanced1(string s) {
    int n = s.size();
    int maxlen = 1;
    vector<int> letter_count(26,0);
    for(int i = 0;i<n;i++){
        letter_count.assign(26,0);
        for(int j = i;j<n;j++){
            letter_count[s[j] - 'a' ]++;
            if(checkBalanced(letter_count)){
                maxlen = max(maxlen,j-i+1);
            }
        }
    }
    return maxlen;
}


int longestBalanced2(string s) {
    int n = s.size();

    // Transform char -> int
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        a[i] = s[i] - 'a';

    int result = 0;
    for (int l = 0; l < n; ++l) {
        // Early exit, can't be bigger
        if (n - l <= result) break;

        int cnt[26] = {0};          // Counts of every char
        int uniq = 0, maxfreq = 0;  // Number of uniq chars and maximum frequency
        for (int r = l; r < n; ++r) {
            int i = a[r];

            // There was no this char before => one more uniq
            if (cnt[i] == 0) ++uniq;

            ++cnt[i];
            // Update max frequency
            if (cnt[i] > maxfreq) 
                maxfreq = cnt[i];

            // Check if all uniq chars have maxfreq frequency then update the result
            int cur = r - l + 1;
            if (uniq * maxfreq == cur && cur > result)
                result = cur;
        }
    }
    return result;
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