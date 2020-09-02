/* Find all root-to-leaf paths where each path's sum equals the given sum.
 * Path sum 2: https://leetcode.com/problems/path-sum-ii/
 */

vector <vector<int>> res;
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (root == nullptr)
        return res;

    vector <int> nodes;        
    traverseAndSum(root, sum, 0, nodes);
    return res;
}

void traverseAndSum(TreeNode* root, int sum, int pathSum, vector<int> nodes){
    nodes.push_back(root->val);
    if (root->val+pathSum == sum){
        if (root->left == nullptr && root->right == nullptr){
            //cout<<nodes.size();
            res.push_back(nodes);
        }
    }

    if (root->left != nullptr)
        traverseAndSum(root->left, sum, root->val+pathSum, nodes);
    if (root->right != nullptr)
        traverseAndSum(root->right, sum, root->val+pathSum, nodes);
}
