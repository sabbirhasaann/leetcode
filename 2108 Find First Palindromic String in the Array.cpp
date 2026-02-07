// 2026/02/07 21:31:26

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string firstPalindrome(vector<string>& words) {
    for(string x: words){
        bool flag = true;
        for(int i=0,j=x.length()-1;i<j;++i,--j)
        {
            if(x[i]!=x[j]){
                flag = false;
                break;
            }
        }
        if(flag)
            return x;
    }

    return "";
}

string firstPalindrome1(vector<string>& words) {
    string str = "";
    int n = words.size();
    for(int i = 0;i < n;i++){
        string s = words[i];
        int l = 0,r = s.length()-1;
        bool yes = true;
        while(l < r){
            if(s[l] != s[r]){
                yes = false;
                break;
            }
            l++,r--;
        }
        if(yes == true){
            str = s;
            break;
        }
    } 
    return str;
}

void soln()
{
    vector<string> words = {"abc","car","ada","racecar","cool"};
    cout << firstPalindrome(words) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}