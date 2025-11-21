class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int first[26], last[26];
        
        fill(first, first+26, -1);
        fill(last, last+26, -1);

        // find first and last positions
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;

        // check each letter as first and last char of palindrome
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c]) continue;

            unordered_set<char> mid;
            for (int i = first[c] + 1; i < last[c]; i++) {
                mid.insert(s[i]);
            }
            ans += mid.size();
        }

        return ans;
    }
};
