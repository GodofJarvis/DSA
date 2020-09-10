/* Lowest Common Ancestor of a Binary Tree - Using parent pointer.
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */

    bool pvisited = false, qvisited = false;
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;

        lca(root, p, q, root);
        return res;
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode *parent){
        if (root == p){
            pvisited = true;
        }
        if (root == q){
            qvisited = true;
        }
        
        if (pvisited && qvisited){
            res = parent;
            return res;
        }
        
        if (root->left != nullptr){
            if (pvisited && qvisited)
                return parent;
            if (pvisited || qvisited)
                lca(root->left, p, q, parent);
            else
                lca(root->left, p, q, parent->left);

        }
        
        if (root->right != nullptr){
            if (pvisited && qvisited)
                return parent;
            if (pvisited || qvisited)
                lca(root->right, p, q, parent);
            else
                lca(root->right, p, q, parent->right);
        }
        return parent;
    }
