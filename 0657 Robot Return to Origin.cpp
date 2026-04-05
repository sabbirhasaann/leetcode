// 2026/04/05 12:37:28
// https://leetcode.com/problems/robot-return-to-origin/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

bool judgeCircle(string moves) {
        int x = 0,y = 0;
        for(int i=0;i<moves.length();++i)  {
            if(moves[i]=='U')
                ++x;
            else if(moves[i]=='D')
                --x;
            else if(moves[i]=='R')
                ++y;
            else
                --y;
        }   

        return x==0 && y==0;
    }

void soln()
{
    vector<string> testSet{
        "UD",
        "LL"
    };
    for(int i=0;i<testSet.size();++i){
        
        auto start = high_resolution_clock::now();
        cout << judgeCircle(testSet[i])<< endl;
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