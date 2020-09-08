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
        
        cout<<root->val<<" "<<lheight<<" "<<rheight<<"\n";

        *dia = max(*dia, lheight + rheight);

        return 1 + max(lheight, rheight);
    }
