class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> v1;
        vector<int> v2;

      if(s.length()>=a.length()){  for(int i=0;i<=s.length()-a.length();i++){
            if(s.substr(i,a.length())==a)v1.push_back(i);
        }
    }
       if(s.length()>=b.length()) {
        for(int i=0;i<=s.length()-b.length();i++){
            if(s.substr(i,b.length())==b)v2.push_back(i);
        }
       }
        if(v1.empty()||v2.empty())return {};
      vector<int>ans;
      for(const auto it:v1){
        for(const auto it2:v2){
            if(abs(it-it2)<=k){
                ans.push_back(it);
                break;
            }
        }
      }
        return ans;
    }
};