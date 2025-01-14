class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        
        vector<pair<int,int>> v;
        int n =aliceValues.size();
        for(int i =0;i<n;i++){
            v.push_back({aliceValues[i],bobValues[i]});
        }
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if((a.first + a.second) == (b.first + b.second)){
                a.first>b.first;
            }
        return (a.first + a.second) > (b.first + b.second);
    });

    int alice = 0;
    int bob = 0;

    for(int i=0;i<n;i++){
        if(i%2==0)alice+=v[i].first;
        else bob+=v[i].second;
    }
    if(alice==bob)return 0;
    else if(alice>bob) return 1;
    else return -1;
    }
};