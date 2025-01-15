class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        int len = 0;
        map<int,int>mpp;

        for(int right=0;right<nums.size();right++){
           
            mpp[nums[right]]++;

            while(mpp[nums[right]]>k){
                mpp[nums[left]]--;
                left++;
                len--;
            }
            len++;
            ans=max(ans,len);
        }
        return ans;
    }
};