// 2026/01/26 17:06:17

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> res;

    int n = arr.size();
    sort(arr.begin(), arr.end());
    int minD = INT_MAX;

    for(int i=0;i<n;i++){
        if(i+1 < n && arr[i+1] - arr[i] < minD)
            minD = arr[i+1] - arr[i];
    }

    for(int i=0;i<n;i++){
        if(i+1 < n && arr[i+1] - arr[i] == minD)
            res.push_back({arr[i], arr[i+1]});
    }

    
    return res;
}

void printMatrix(vector<vector<int>> res){

    for(vector<int> v: res)
    {
        for(int x: v)
            cout << x <<" ";
        cout << endl;
    }
    cout << endl;

}

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    //o/(n)+o(nlogn)
    vector<vector<int>>res;
    int mindiff=abs(arr[0]-arr[1]);
    
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++){
        int currdiff=abs(arr[i]-arr[i+1]);
        if(currdiff<mindiff) {         
            mindiff=currdiff;
            res.clear();
            res.push_back({arr[i],arr[i+1]});
        }
        else if(currdiff==mindiff){    
            res.push_back({arr[i],arr[i+1]});
        }
    }
    return res;
}

void soln()
{
    vector<int> arr = {4,2,1,3};
    vector<vector<int>> res = minimumAbsDifference(arr);
    printMatrix(res);


    arr = {1,3,6,10,15};
    res = minimumAbsDifference(arr);
    printMatrix(res);

    arr = {3,8,-10,23,19,-4,-14,27};
    res = minimumAbsDifference(arr);
    printMatrix(res);
    

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}