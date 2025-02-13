#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int longestDupSubstring(std::string s) {
    int left = 1, right = s.size();
    int result = 0;
    
    auto hasDuplicate = [&](int len) {
        std::unordered_set<std::string> seen;
        long long hash = 0, base = 257, mod = 1e9 + 7;
        long long baseL = 1;
        
        for (int i = 0; i < len; i++) baseL = (baseL * base) % mod;

        for (int i = 0; i < len; i++) {
            hash = (hash * base + s[i]) % mod;
        }
        seen.insert(s.substr(0, len));

        for (int i = len; i < s.size(); i++) {
            hash = (hash * base - s[i - len] * baseL % mod + mod) % mod;
            hash = (hash + s[i]) % mod;
            if (seen.find(s.substr(i - len + 1, len)) != seen.end()) return true;
            seen.insert(s.substr(i - len + 1, len));
        }
        return false;
    };

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (hasDuplicate(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    std::string s = "banana";
    std::cout << longestDupSubstring(s) << std::endl;
    return 0;
}
