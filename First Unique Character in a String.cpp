class Solution {
public:
      int firstUniqChar(const std::string& s) {
        std::vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            ++freq[ch - 'a'];
        }

        // Find the first unique character
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1; // No unique character found
    }
};
