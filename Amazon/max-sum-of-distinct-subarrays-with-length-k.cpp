class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0 ;
        int left = 0;
        map<int,int>mpp;
        long long sum = 0;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
            sum+= nums[i];
            while(i-left+1>k || mpp[nums[i]]>1){
                sum -= nums[left];
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            
          if(i-left+1==k && mpp.size()==k) ans=max(sum,ans);
            
        }
        return ans;
    }
};