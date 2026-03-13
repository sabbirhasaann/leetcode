// 2026/03/13 19:59:49
// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();++i){
            if(st.empty())
                st.push(s[i]);
            else{
                char t = st.top();
                if(t=='(' && s[i]==')')
                    st.pop();
                else if(t=='{' && s[i] == '}')
                    st.pop();
                else if(t=='[' && s[i] == ']')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        if(st.empty())
            return true;
        return false;
    }

void soln()
{
    vector<string> testSet{
        "()",
        "()[]{}",
        "(]",
        "([])",
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << isValid(testSet[i])<< endl;
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