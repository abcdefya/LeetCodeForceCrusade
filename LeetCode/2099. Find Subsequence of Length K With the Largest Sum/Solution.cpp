class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Pair each value with its index
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); ++i) {
            indexed_nums.push_back({nums[i], i});
        }

        // Sort by value in descending order
        sort(indexed_nums.begin(), indexed_nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        // Take the top k elements
        vector<pair<int, int>> top_k(indexed_nums.begin(), indexed_nums.begin() + k);

        // Sort the top k elements by original index to maintain subsequence order
        sort(top_k.begin(), top_k.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        // Extract the values to return
        vector<int> result;
        for (const auto& p : top_k) {
            result.push_back(p.first);
        }

        return result;
    }
};
