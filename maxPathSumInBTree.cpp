/* https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * 
 * Given a non-empty binary tree, find the maximum path sum.
 * a path is defined as any sequence of nodes from some starting 
 * node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the root.
 */
    
    int maxSum = 0;
    int maxPathSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        maxSum = root->val;
        eachPathSum(root);
        return maxSum;
    }
    
    int eachPathSum(TreeNode* root){
        if (root == nullptr)
            return 0;
        
        int lSum = eachPathSum(root->left);
        int rSum = eachPathSum(root->right);
        
        int pathSum = 0;
        if (lSum > 0)
            pathSum += lSum;
        if (rSum > 0)
            pathSum += rSum;
        
        maxSum = max(maxSum, pathSum + root->val);
        
        if (max(lSum, rSum) > 0)
            return root->val + max(lSum, rSum);
        return root->val;
    }
