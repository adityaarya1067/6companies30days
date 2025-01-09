class Solution {
private:
    //function for finding the minumum ans using recursion
    pair<string, int> solve(int i, int j, vector<int>& arr, vector<vector<pair<string, int>>> & dp){
        if(i == j){
            string st = "";
            st += ('A' + i - 1);
            return {st, 0};
        };
        
        if(dp[i][j].second != -1){
            return dp[i][j];
        }
        
        int mini = 1e9;
        string str= "";
        for(int k =i; k < j; k++){
            
            auto f1 = solve(i, k, arr, dp);
            auto f2 = solve(k + 1, j, arr, dp);
            int steps = arr[i -1]*arr[k]*arr[j] + f1.second + f2.second;
             
            if (steps < mini) {
                mini = steps;
                str = '(' + f1.first + f2.first + ')';
            }
        }
        
        dp[i][j] = {str, mini};
        return dp[i][j];
    }
  public:
    string matrixChainOrder(vector<int> &arr) {
        int n= arr.size();
        vector<vector<pair<string, int>>>dp(n, vector<pair<string, int>>(n, {"", -1}));
        auto ans = solve(1, n- 1, arr, dp);
        return ans.first;
    }
};