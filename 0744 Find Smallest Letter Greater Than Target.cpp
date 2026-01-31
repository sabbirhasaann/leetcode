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