class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const int MAX_VAL = 100;
        vector<int> cnt(MAX_VAL + 2, 0);       

        for (int x : nums)
            cnt[x + 1]++;

        for (int v = 1; v < (int)cnt.size(); v++)
            cnt[v] += cnt[v - 1];

        vector<int> res;
        res.reserve(nums.size());
        for (int x : nums)
            res.push_back(cnt[x]);
        return res;
    }
};
