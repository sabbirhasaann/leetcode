#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s){

    unordered_map<char, int> lastSeen;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); right++) {
        char current = s[right];

        if (lastSeen.find(current) != lastSeen.end() && lastSeen[current] >= left) 
            left = lastSeen[current] + 1;
            
            
        
        lastSeen[current] = right;
        maxLength = max(maxLength, right-left+1);
    }

    return maxLength;
}

int main() {
    cout << lengthOfLongestSubstring("abac") << endl; // expected 3
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    cout << lengthOfLongestSubstring("abcedebacf") << endl; // expected 6
    cout << lengthOfLongestSubstring("abecdeghif") << endl;

    

    return 0;
}