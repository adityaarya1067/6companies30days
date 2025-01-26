class Solution {
public:
    vector<vector<int>> combinations;

    void findCombinations(int start, int count, int target, int currentSum, vector<int>& combination) {  
        if (currentSum == target && count == 0) {
            combinations.push_back(combination);
            return; 
        }    

        for (int i = start; i <= 9; i++) {     
            combination.push_back(i);
            findCombinations(i + 1, count - 1, target, currentSum + i, combination);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int count, int target) {
        vector<int> combination;
        findCombinations(1, count, target, 0, combination);
        return combinations;
    }
};
