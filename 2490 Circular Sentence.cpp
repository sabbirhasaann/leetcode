#include <bits/stdc++.h>
using namespace std;

bool isCircularSentence(string sentence)
{
    int len = sentence.size();
    if (sentence[0] != sentence[len - 1])
        return false;
    for (int i = 1; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ')
        {
            if (sentence[i - 1] != sentence[i + 1])
                return false;
        }
    }
    return true;
}
int main()
{
    string s;
    getline(cin, s);

    cout << isCircularSentence(s);
}