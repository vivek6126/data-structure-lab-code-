#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Move map entries into a vector of pairs
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        // Sort the vector in descending order of frequency
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return b.second > a.second;
        });

        // Collect the top k frequent elements
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};