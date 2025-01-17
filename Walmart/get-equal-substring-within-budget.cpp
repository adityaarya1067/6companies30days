class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> ascii;
        int n =s.length();
        for(int i=0;i<n;i++){
            ascii.push_back(abs((s[i]-'a')-(t[i]-'a')));
        }
        int ans = 0;
        int sum = 0;
        int left = 0;
        int len = 0;
        for(int i=0;i<n;i++){
                sum+=ascii[i];
                len++;
            while(sum>maxCost){
                sum-=ascii[left];
                left++;
                len--;
            }
           ans=max(len,ans);
        }
        return ans;
    }
};