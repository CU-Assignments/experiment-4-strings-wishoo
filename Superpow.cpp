#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1337;

// Function to compute (a^b) % mod using modular exponentiation
int powerMod(int a, int b, int mod) {
    int result = 1;
    a %= mod; // Reduce 'a' mod 'mod' first

    while (b > 0) {
        if (b % 2 == 1) {  // If b is odd, multiply result with a
            result = (result * a) % mod;
        }
        a = (a * a) % mod; // Square the base
        b /= 2;
    }
    return result;
}

// Function to compute super power using recursion
int superPowHelper(int a, vector<int>& b, int index) {
    if (index < 0) return 1; // Base case: If b is empty, return 1

    int lastDigit = b[index]; // Get the last digit
    int part1 = powerMod(a, lastDigit, MOD); // Compute (a^lastDigit) % MOD
    int part2 = powerMod(superPowHelper(a, b, index - 1), 10, MOD); // Compute ((a^rest) ^ 10) % MOD

    return (part1 * part2) % MOD;
}

int superPow(int a, vector<int>& b) {
    return superPowHelper(a, b, b.size() - 1);
}

// Main function
int main() {
    int a = 2;
    vector<int> b = {1, 0}; // Example: 2^10 mod 1337
    cout << "Result: " << superPow(a, b) << endl; // Output: 1024

    return 0;
}
