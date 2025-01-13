class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count= 0;
        int child=0;
        int cookie=0;
        while(child<g.size() && cookie<s.size()){
            if(s[cookie]>=g[child]){
                count++;
                child++;
            }
            cookie++;
        }
        return count;
    }
};