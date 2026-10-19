class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int j = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == s[j])
                j++;
        }

        if (j == n)
            return s;

        string rem = s.substr(j);
        reverse(rem.begin(), rem.end());

        return rem + shortestPalindrome(s.substr(0, j)) + s.substr(j);
    }
};