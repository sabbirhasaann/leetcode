// 2025/11/24 21:05:08

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res;
    int ans =  0;

    for(int x: nums){
        ans = ans << 1;
        ans |= x;
        if(!(ans%5))
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
}
void printArray(vector<bool> &v)
{
    for (bool x : v)
        x ? cout << "True " : cout << "False ";
    cout << endl;
}
void soln()
{
    vector<int> nums;

    nums = {0,1,1};
    vector<bool> res = prefixesDivBy5(nums);
    printArray(res);

    nums = {1,1,1};
    res = prefixesDivBy5(nums);
    printArray(res);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}