#include <bits/stdc++.h>
using namespace std;
string compressedString(string word)
{
    int n = word.size();
    string comp;
    for (int i = 0; i < n;)
    {
        char temp = word[i];
        int count = 1;

        while (temp == word[++i] && count < 9)
            count++;

        comp = comp + to_string(count) + temp;
    }

    return comp;
}
int main()
{
    string word;
    cin >> word;

    string compressed = compressedString(word);
    cout << compressed << endl;
}
