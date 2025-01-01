class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int curr = 0;int ans = 0;

       map<int,int> mpp;
       mpp[curr]=1;

       for(int i=0;i<nums.size();i++){
        curr += nums[i]%2;

        if(mpp.find(curr-k) != mpp.end()){
            ans+= mpp[curr-k];
        }
        mpp[curr]++;
       }
       return ans;
    }
};