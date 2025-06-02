#include <bits/stdc++.h>
using namespace std;
vector<string> split_sentence(string sen)
{
    stringstream ss(sen);
    string word;
    vector<string> words;
    while (ss >> word)
        words.push_back(word);
    return words;
}
int isPrefixOfWord(string sentence, string searchWord)
{
    vector<string> words = split_sentence(sentence);
    for (int i = 0; i < words.size(); ++i)
        if (words[i].substr(0, searchWord.size()) == searchWord)
            return i + 1;

    return -1;
}
int main()
{
    string sentence;
    string searchword;
    getline(cin, sentence);
    cin >>
        searchword;

    cout << isPrefixOfWord(sentence, searchword);
    return 0;
}