/* Increasing Order Search Tree ==> Right Skew tree
 *
 * https://leetcode.com/problems/increasing-order-search-tree/
 * Given a binary search tree, rearrange the tree in in-order so that the leftmost node 
 * in the tree is now the root of the tree, and every node has no left child and only 1 right child.
 *
 */

#include <bits/stdc++.h> 
using namespace std; 

struct Node{
  int data;
  Node *left;
  Node *right;
  
  Node(int x): data(x), left(nullptr), right(nullptr){}
};

int disp(Node *ptr, int level){
    if (ptr->right != nullptr)
        disp(ptr->right, level+1);
    cout<<"\n";
    for (int i=0; i<level; i++){
        cout<<"  ";
    }
    cout<<ptr->data;
    if (ptr->left != nullptr)
        disp(ptr->left, level+1);
}

Node *modifyTree(Node *root){
    while(root->left != nullptr){
        Node *ptr = root->left;
        for (; ptr->right != nullptr; ptr=ptr->right);

        ptr->right = root;
        ptr = root->left;
        root->left = nullptr;
        root = ptr;
    }
    return root;
}

Node *increasingOrderBST(Node *root){
    root = modifyTree(root);
    if (root->right == nullptr)
        return root;

    Node *prev = root;
    Node *ptr = root->right;
    while (ptr != nullptr){
        if (ptr->left != nullptr) { 
            ptr = modifyTree(ptr);
            prev->right = ptr;
        }
        
        prev = prev->right;
        ptr = ptr->right;
    }
    return root;
}

int main()
{
	Node* root = new Node(5);
	root->left = new Node(3);
	root->right = new Node(6);
	root->left->left = new Node(2);
	root->left->right = new Node(4);
	root->right->right = new Node(8);
	root->left->left->left = new Node(1);
	root->right->right->left = new Node(7);
	root->right->right->right = new Node(9);

	disp(root, 0);
	root = increasingOrderBST(root);
	disp(root, 0);
	return 0; 
} 
