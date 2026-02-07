// 2026/02/07 08:06:38

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int minimumDeletions(string s) {
    
    int res = 0;
    int countB = 0;
    
    for (char c : s) {
        if (c == 'b') {
            countB++;
        } else {
            res = min(res + 1, countB);
        }
    }
    
    return res;    
}

int minimumDeletions1(string s) {
    int res = 0, count = 0;
    for (char c : s){
        if (c == 'b')
            count++;
        else if (count){
            res++;
            count--;
        }
    }
    return res;
}

int minimumDeletions2(string s) {
    int bCount = 0;     // number of 'b' seen so far
    int deletions = 0;  // minimum deletions

    for(char c : s) {
        if(c == 'b') {
            bCount++;
        } else { // c == 'a'
            if(bCount > 0) {
                deletions++;
                bCount--;   // delete one previous 'b'
            }
        }
    }
    return deletions;
}

void soln()
{
    string s = "baababbaabbaaabaabbabbbabaaaaaabaabababaaababbb";
    cout << minimumDeletions(s) << endl;
    
    s = "aababbab";
    cout << minimumDeletions(s) << endl;
    
    s = "bbaaaaabb";    
    cout << minimumDeletions(s) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}