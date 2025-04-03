class Solution {
public:
      int firstUniqChar(const std::string& s) {
        std::vector<int> freq(26, 0);

     
        for (char ch : s) {
            ++freq[ch - 'a'];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
      }
};
