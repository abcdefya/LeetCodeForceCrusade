#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            unordered_map<int, int> comp;
            for (int i = 0; i < nums.size(); ++i){
                int complement = target - nums[i];
                if(comp.count(complement)) {
                    return {comp[complement], i};
                }
                comp[nums[i]] = i;
            }
            return {};
        }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, target;
    cin >> n >> target;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<int> result = sol.twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}