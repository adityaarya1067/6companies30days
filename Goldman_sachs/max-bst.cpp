class Solution {
public:
    int findMaxSum(TreeNode* root) {
        int result = 0;
        using NodeData = tuple<bool, int, int, int>; // isValidBST, sum, maxValue, minValue
        function<NodeData(TreeNode*)> traverse = [&](TreeNode* node) -> NodeData {
            if (node == nullptr) return {true, 0, INT_MIN, INT_MAX};
            
            auto [isLeftBST, leftSum, leftMax, leftMin] = traverse(node->left);
            auto [isRightBST, rightSum, rightMax, rightMin] = traverse(node->right);
            
            bool isCurrentBST = isLeftBST && isRightBST && node->val > leftMax && node->val < rightMin;
            int currentSum = node->val + leftSum + rightSum;
            
            if (isCurrentBST) result = max(result, currentSum);
            
            return {isCurrentBST, currentSum, 
                    max(node->val, max(rightMax, leftMax)), 
                    min(node->val, min(leftMin, rightMin))};
        };
        
        traverse(root);
        return result;
    }
};
