#include "longestSubstring.h"

int Solution::lengthOfLongestSubstring(string s) {
    int s_size = s.length();
    int result = 1;
    int ar[s_size];
    ar[0] = 1;
    for (int i = 1; i < s_size; ++i) {
        ar[i] = ar[i-1] + 1;
        for (int j = i-ar[i-1]; j < i; ++j) {
            if (s[j] == s[i]) {
                ar[i] = i - j;
                break;
            }
        }
        if (ar[i] > result) result = ar[i];
    }
    return result;
}

int main () {
    string s = "bpfbhmipx";
    int result = Solution::lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}
