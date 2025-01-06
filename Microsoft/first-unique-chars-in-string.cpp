class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mpp;
        char a;
        int ans = 0 ;
        vector<char> v;
        for(int i=0;i<s.length();i++){
            if(mpp.find(s[i])==mpp.end()){
                v.push_back(s[i]);
            }
            mpp[s[i]]++;
        }
         
       for(int i=0;i<v.size();i++){
        if(mpp[v[i]]==1){
            a=v[i];
            break;
        }
       }
       for(int i=0;i<s.length();i++){
            if(a==s[i]){
                return i;
            }
       }
        return -1 ;
    }
};