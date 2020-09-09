/* Most simplest way of finding diameter of a tree.
 * https://leetcode.com/problems/diameter-of-binary-tree/
 */

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int dia = 0;
        diameter(root, &dia);
        return dia;
    }
    
    int diameter(TreeNode* root, int *dia){
        if (root == nullptr)
            return 0;
        int lheight = diameter(root->left, dia);
        int rheight = diameter(root->right, dia);

        *dia = max(*dia, lheight + rheight);

        return 1 + max(lheight, rheight);
    }
