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

string intToRoman1(int num)
{
    vector<int> values = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1};

    vector<string> symbols = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"};

    string result = "";

    for (int i = 0; i < values.size(); i++)
    {
        while (num >= values[i])
        {
            num -= values[i];
            result += symbols[i];
        }
    }

    return result;
}

string intToRoman2(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string thousands[] = {"", "M", "MM", "MMM"};

    string Roman = thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    return Roman;
}

string intToRoman3(int num)
{
    string Roman = "";

    vector<pair<int, string>> storeIntRoman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    for (int i = 0; i < storeIntRoman.size(); i++)
    {
        while (num >= storeIntRoman[i].first)
        {
            Roman += storeIntRoman[i].second;
            num -= storeIntRoman[i].first;
        }
    }
    return Roman;
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

string intToRoman4(int num)
{
    string ans = "";
    vector<pair<int, string>> table = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    for (auto [val, cha] : table)
    {
        while (num >= val)
        {
            ans += cha;
            num -= val;
        }
    }
    return ans;
}

string intToRoman5(int num)
{
    const vector<pair<int, string>> valueSymbols{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string res;

    for (const auto &[value, symbol] : valueSymbols)
    {
        if (num == 0)
            break;

        while (num >= value)
        {
            res += symbol;
            num -= value;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    soln();
    return 0;
}