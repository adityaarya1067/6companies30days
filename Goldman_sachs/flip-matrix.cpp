class Solution {
public:
    int rows, cols;
    int rowIndex = 0, colIndex = 0;

    Solution(int m, int n) {
        this->cols = n;
        this->rows = m;
    }
    
    vector<int> flip() {
        int r = rowIndex, c = colIndex;
        if (colIndex + 1 < cols) colIndex++;
        else if (rowIndex + 1 < rows) {
            rowIndex++;
            colIndex = 0;
        }
        else {
            rowIndex = 0;
            colIndex = 0;
        }
        return {r, c};
    }
    
    void reset() {}
};
