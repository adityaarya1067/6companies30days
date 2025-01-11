class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>> v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[](const auto&a,const auto &b){
          return  a.second<b.second;
        });
        string ans ="";
        for(int i=0;i<v.size();i++){
         while(v[i].second--)   ans+=v[i].first;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};