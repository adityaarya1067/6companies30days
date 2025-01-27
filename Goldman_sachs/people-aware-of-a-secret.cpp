class Solution {
    int memo[1001];
    #define MOD 1000000007
public:
    int helper(int currentDay, int delay, int forget, int totalDays) {
        if (currentDay + delay > totalDays) return 1;
        if (memo[currentDay] != -1) return memo[currentDay];
        
        int result = 1;
        for (int nextDay = currentDay + delay; nextDay <= min(totalDays, currentDay + forget); ++nextDay) {
            if (nextDay == currentDay + forget) {
                result -= 1;
                break;
            }
            result = (result % MOD + helper(nextDay, delay, forget, totalDays) % MOD) % MOD;
        }
        
        return memo[currentDay] = result;
    }
    
    int peopleAwareOfSecret(int totalDays, int delay, int forget) {
        memset(memo, -1, sizeof(memo));
        return helper(1, delay, forget, totalDays);
    }
};
