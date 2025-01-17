class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
       int ans = 0;
       set<pair<int,int>> st;
        for(int i=nums.size()-1;i>0;i--){
            int num = nums[i]-k;
            auto it = lower_bound(nums.begin(),nums.begin()+i-1,num);
            if(it!=nums.end() && (nums[i]-nums[it-nums.begin()])==k){
                st.insert({nums[it-nums.begin()],nums[i]});
            }
        }
        return st.size();
    }
};