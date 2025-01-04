class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>ans(nums.begin(),nums.end());
        sort(ans.begin(),ans.end());
        int n =nums.size();
        int k = n-1;
        for(int i=1;i<n;i=i+2){
            nums[i] = ans[k];
            k--;
        }
        for(int i=0;i<n;i=i+2){
            nums[i] = ans[k];
            k--;
        }
    }
};