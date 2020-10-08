/* Delete a node in BST in O(height_of_tree).
 * https://leetcode.com/problems/delete-node-in-a-bst/
 */


    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;
        return searchDelete(root, key);
    }
    
    TreeNode* searchDelete(TreeNode* root, int key){
        if (root == nullptr)
            return root;

        if (key > root->val){
            root->right = searchDelete(root->right, key);
        }
        else if (key < root->val){
            root->left = searchDelete(root->left, key);
        }
        
        else if (key == root->val) {
            if (root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            else {
                TreeNode* replaceNode = root->right;
                TreeNode* replaceParent = root;

                while(replaceNode->left != nullptr){
                    replaceParent = replaceNode;
                    replaceNode = replaceNode->left;
                }
                
                if (root == replaceParent)
                    replaceParent->right = replaceNode->right;
                else
                    replaceParent->left = replaceNode->right;
                
                root->val = replaceNode->val;
                delete replaceNode;
                return root;
            }
        }
        return root;
    }
