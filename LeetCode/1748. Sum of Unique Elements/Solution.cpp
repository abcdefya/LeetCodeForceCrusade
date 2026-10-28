class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> count;              // giá trị → số lần xuất hiện
        for (int x : nums)
            count[x]++;

        int total = 0;
        for (auto [key, value] : count)
            if (value == 1)
                total += key;
        return total;
    }
};