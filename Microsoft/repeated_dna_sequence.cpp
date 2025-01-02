class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n =s.length();
        string a = "";
        map<string,int> mpp;
        int left = 0;

        for(int right = 0;right<n;right++){
            
            if(right-left>=10){
                left++;
                mpp[a]++;
                a.erase(0,1);
            }
            a+=s[right];
        }
        mpp[a]++;
        vector<string> ans;
        for(const auto&it:mpp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};