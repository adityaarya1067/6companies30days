class Solution {
public:
    string convertToTitle(int c) {
        string ans = "";

        while (c>0){
            c--;
            int p = c%26;
        
            ans+=p+'A' ;
            
            c/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};