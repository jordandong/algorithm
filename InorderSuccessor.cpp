/*
 * In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree.
 * Inorder Successor is NULL for the last node in Inoorder traversal.
 * In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of input node.
 * So, it is sometimes important to find next node in sorted order.
 */

BinaryTree * inOrderSuccessor(BinaryTree *n, BinaryTree* target, bool& indicator){  
	if( n== NULL )  
		return NULL;  
	
	BinaryTree* left = inOrderSuccessor(n->left, target, indicator);
	if(left != NULL)
		return left; 
		
	if(indicator)
		return n;  
	if(n == target)
		indicator = true;
	
	BinaryTree* right =inOrderSuccessor(n->right, target, indicator);  
	if(right!= NULL)
		return right;  
	return NULL;  
}

int main(){
	BinaryTree* root = new BinaryTree(30);
	root->left = new BinaryTree(10);
	root->right = new BinaryTree(40);
	root->left->left = new BinaryTree(5);
	root->left->right = new BinaryTree(15);
	//root->right->left = new BinaryTree(35);
	root->right->right = new BinaryTree(45);

	bool ind = false;
	BinaryTree* res = inOrderSuccessor(root, root, ind);
	cout<<endl;
	if(res)
		cout<<res->data<<endl;
	else
		cout<<"#"<<endl;

	return 0;
}
