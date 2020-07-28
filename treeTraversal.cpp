#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
	Node (int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

void recursiveInOrder(struct Node *ptr)
{
    if (ptr->left != NULL)
        recursiveInOrder(ptr->left);
    cout<<ptr->data<<" ";
    if (ptr->right != NULL)
        recursiveInOrder(ptr->right);
}

void stackInOrder(struct Node *root) 
{ 
	stack<Node *> s; 
	Node *ptr = root;
	
	while (ptr!=NULL || !s.empty()){
	    
	    while (ptr != NULL){
	        s.push(ptr);
	        ptr = ptr->left;
	    }
	    ptr = s.top();
	    s.pop();
	    
	    cout<<ptr->data<<" ";
	    ptr = ptr->right;
	}

} 

int main() 
{ 

	/* Constructed binary tree is 
			 1 
		   /   \ 
		 2	    3 
		/ \    /  \
	  4	  5   6    7
	*/
	struct Node *root = new Node(1); 
	root->left	 = new Node(2); 
	root->right	 = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	root->right->left = new Node(6); 
	root->right->right = new Node(7); 

    
	stackInOrder(root); 
	cout<<"\n";
	recursiveInOrder(root);
	return 0; 
} 
