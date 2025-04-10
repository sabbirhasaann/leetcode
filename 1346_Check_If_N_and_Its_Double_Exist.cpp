#include <bits/stdc++.h>
using namespace std;
bool checkIfExist(vector<int> &arr)
{

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
            if (i != j && arr[i] == 2 * arr[j] || 2 * arr[i] == arr[j])
                return true;
    }

    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << checkIfExist(arr);
}