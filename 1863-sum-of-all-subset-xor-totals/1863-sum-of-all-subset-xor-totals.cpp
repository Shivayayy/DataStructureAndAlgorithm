class Solution {
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result |= num;
        }
        return result << (nums.size() - 1);
    }
};