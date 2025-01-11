class Solution {
public:
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mpp;
        
        for(int i =0;i<words.size();i++){
            mpp[words[i]]++;
        }
        vector<pair<string,int>> v(mpp.begin(),mpp.end());
       sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;  
            }
            return a.second > b.second;  
        });
        vector<string>t;

       for(int i =0;i<k;i++){
        t.push_back(v[i].first);
       }
        return t;
    }
};