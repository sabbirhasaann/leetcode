#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (char c = 'a'; c <= 'z'; c++)
        cout << (25 - (c - 'a')) % 26 << endl;
    for (int i = 0; i < 26; ++i)
        cout << (char)(25 - i + 'a') << endl;
}