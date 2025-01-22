class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> uniqueSubarrays;

        for (int i = 0; i < n; i++) {
            vector<int> subarray;
            int countDivisible = 0;

            for (int j = i; j < n; j++) {
                subarray.push_back(nums[j]);

                if (nums[j] % p == 0) {
                    countDivisible++;
                }

                if (countDivisible > k) {
                    break;
                }

                uniqueSubarrays.insert(subarray);
            }
        }

        return uniqueSubarrays.size();
    }
};
