class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());

        while(k--){
            int num = pq.top();
            pq.pop();
            num++;
            pq.push(num);
        }
        long long sum = 1;

        while(!pq.empty()){
            int num = pq.top();
            sum*= num;
            pq.pop();
            sum =sum%1000000007;
        }
        return sum;
    }
};