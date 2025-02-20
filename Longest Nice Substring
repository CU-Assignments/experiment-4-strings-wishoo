#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string longestNiceSubstring(string s) {
    if (s.length() < 2) return "";

    unordered_set<char> charSet(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If one case exists but not the other, split and check recursively
        if (charSet.count(tolower(ch)) == 0 || charSet.count(toupper(ch)) == 0) {
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            return left.length() >= right.length() ? left : right;
        }
    }
    return s; // If the whole string is nice
}

int main() {
    string s = "YazaAay";
    cout << "Longest Nice Substring: " << longestNiceSubstring(s) << endl; // Output: "aAa"
    return 0;
}
