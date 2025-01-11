class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
      
        int n=nums.size();
        map<int,int> mpp;
        
        
        vector<pair<int,int>> v;

        for(int i = 0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),[](const auto &a,const auto &b){
            if(a.first==b.first){
                a.second<b.second;
            }
            return a.first<b.first;
        });

        vector<pair<int,int>> ans;
        int p = v.size()-1;
        while(k--){
            ans.push_back(v[p]);
            p--;
        }
         sort(ans.begin(),ans.end(),[](const auto &a,const auto &b){

            return a.second<b.second;
        });
        vector<int> l;

        for(int i=0;i<ans.size();i++){
            l.push_back(ans[i].first);
        }

        
        return l;
    }
};