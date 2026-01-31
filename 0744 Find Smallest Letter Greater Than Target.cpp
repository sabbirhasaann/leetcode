// 2026/01/31 18:33:20

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
char nextGreatestLetter(vector<char>& letters, char target) {
    for(char ch: letters)
        if(ch>target)
            return ch;
    return letters[0]; 
}

char nextGreatestLetter2(vector<char>& letters, char target) {
    int L = 0, R = letters.size() - 1;
    while (L <= R) {
        int M = (L + R) >> 1;
        if (letters[M] > target) R = M - 1;
        else L = M + 1;
    }
    return letters[L % letters.size()];
}

char nextGreatestLetter1(vector<char>& letters, char target) {
    int beg = 0;
    int end = letters.size() - 1;
    char ans = letters[0];

    while (beg <= end) {
        int mid =beg+(end-beg)/ 2;

        if (letters[mid] > target) {
            ans = letters[mid];
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    return ans;
}

void soln()
{
    vector<char> letters = {'c','f','j'};
    char target = 'a';
    cout << nextGreatestLetter(letters, target) << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}