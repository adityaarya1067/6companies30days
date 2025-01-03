class Solution {
public:
    int incremovableSubarrayCount(vector<int>& arr) {
         int result = 0;
        int length = arr.size();
        
        for (int start = 0; start < length; start++) {
            for (int end = start; end < length; end++) {
                bool isValid = true;
                int previous = -1;
                
                for (int idx = 0; idx < length; idx++) {
                    if (idx >= start && idx <= end) {
                        continue;
                    } else {
                        isValid &= (previous < arr[idx]);
                        previous = arr[idx];
                    }
                }
                
                result += isValid;
            }
        }
        return result;
    }
};