// 2026/04/30 19:23:37
// https://leetcode.com/problems/integer-to-roman/

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define endl '\n'

string intToRoman(int num)
{

    string r;
    while (num > 0)
    {
        if (num >= 1 && num < 4)
        {
            num -= 1;
            r += "I";
        }
        else if (num == 4)
        {
            num -= 4;
            r += "IV";
        }
        else if (num >= 5 && num < 9)
        {
            num -= 5;
            r += "V";
        }
        else if (num == 9)
        {
            num -= 9;
            r += "IX";
        }
        else if (num >= 10 && num < 40)
        {
            num -= 10;
            r += "X";
        }
        else if (num >= 40 && num < 50)
        {
            num -= 40;
            r += "XL";
        }
        else if (num >= 50 && num < 90)
        {
            num -= 50;
            r += "L";
        }
        else if (num >= 90 && num < 100)
        {
            num -= 90;
            r += "XC";
        }
        else if (num >= 100 && num < 400)
        {
            num -= 100;
            r += "C";
        }
        else if (num >= 400 && num < 500)
        {
            num -= 400;
            r += "CD";
        }
        else if (num >= 500 && num < 900)
        {
            num -= 500;
            r += "D";
        }
        else if (num >= 900 && num < 1000)
        {
            num -= 900;
            r += "CM";
        }
        else if (num >= 1000)
        {
            num -= 1000;
            r += "M";
        }
    }

    return r;
}

void soln()
{
    vector<int> testSet{
        3749,
        58,
        1994,
        45,
    };
    for (int i = 0; i < testSet.size(); ++i)
    {

        auto start = high_resolution_clock::now();
        cout << intToRoman(testSet[i]) << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " ms" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}