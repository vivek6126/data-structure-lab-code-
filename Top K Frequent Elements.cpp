class Solution {
public:
     std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;
        
        for (int num : nums) {
            ++freq_map[num];
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> min_heap;
        
        for (const auto& [num, freq] : freq_map) {
            min_heap.emplace(freq, num);
            if (min_heap.size() > k) {
                min_heap.pop(); 
            }
        }

       
        std::vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};
