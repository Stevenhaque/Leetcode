class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;

        vector<int> shifts(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            int diff = (t[i] - s[i] + 26) % 26;
            if (diff == 0) continue;

            
            int move = diff + 26 * shifts[diff];
            if (move > k) return false;
            shifts[diff]++;
        }

        return true;
    }
};
