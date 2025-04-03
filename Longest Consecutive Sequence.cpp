class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> num_set(nums.begin(), nums.end());
        int longest = 0;

        for (int num : num_set) {
            if (!num_set.count(num - 1)) {  // Start of a sequence
                int current_num = num;
                int current_streak = 1;

                while (num_set.count(current_num + 1)) {
                    ++current_num;
                    ++current_streak;
                }

                longest = std::max(longest, current_streak);
            }
        }
        return longest;
    }
};
