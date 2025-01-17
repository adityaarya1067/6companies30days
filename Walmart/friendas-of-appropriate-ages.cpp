class Solution {
public:
    
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        int n = ages.size();
       
        sort(ages.begin(), ages.end());
       
       for(int i=0;i<n;i++){
        int age = ages[i];
        if(age<=14)continue;

        int ageMax = (age/2)+7;
        auto lower = upper_bound(ages.begin(),ages.end(),ageMax);
        auto upper = upper_bound(ages.begin(),ages.end(),age);
        int count = upper-lower;
       if(count>0) ans+=count-1;

       }

        return ans ;
    }
};