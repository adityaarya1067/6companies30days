class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Initialize the result matrix
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size(), 0));

        // Traverse through each cell in the image
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[0].size(); j++) {
                int num = img[i][j];
                int count = 1; // Include the current cell

                // Check all 8 neighbors and the current cell
                if (i - 1 >= 0) {
                    num += img[i - 1][j]; // Up
                    count++;
                }
                if (i + 1 < img.size()) {
                    num += img[i + 1][j]; // Down
                    count++;
                }
                if (j - 1 >= 0) {
                    num += img[i][j - 1]; // Left
                    count++;
                }
                if (j + 1 < img[0].size()) {
                    num += img[i][j + 1]; // Right
                    count++;
                }
                if (i + 1 < img.size() && j + 1 < img[0].size()) {
                    num += img[i + 1][j + 1]; // Bottom-right diagonal
                    count++;
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    num += img[i - 1][j - 1]; // Top-left diagonal
                    count++;
                }
                if (i - 1 >= 0 && j + 1 < img[0].size()) {
                    num += img[i - 1][j + 1]; // Top-right diagonal
                    count++;
                }
                if (i + 1 < img.size() && j - 1 >= 0) {
                    num += img[i + 1][j - 1]; // Bottom-left diagonal
                    count++;
                }

                // Compute the average
                ans[i][j] = num / count;
            }
        }

        return ans;
    }
};
