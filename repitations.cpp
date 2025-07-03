#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int maxLen = 1, currentLen = 1;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            currentLen++;
            maxLen = max(maxLen, currentLen);
        } else {
            currentLen = 1;
        }
    }

    cout << maxLen << endl;
    return 0;
}
