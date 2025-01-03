class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        int ans=1;
        int end = INT_MIN;
        sort(v.begin(),v.end(),[](const vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int> dp;

        for(const auto &it:v){
            int h =it[1];

            auto it2 = lower_bound(dp.begin(),dp.end(),h);
            if(it2==dp.end())dp.push_back(h);
            else *it2=h;


        }
      
        
        return dp.size();
    }
};