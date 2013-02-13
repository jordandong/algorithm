/* Insert Node and Delete Node in a BST
 *
 */

#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Insert(TreeNode* &root, int value){
	if(!root)
		root=new TreeNode(value);
	else{
		TreeNode* curr = root;
		while(curr){
			if(curr->val>value){
				if(!curr->left){
					curr->left=new TreeNode(value);
					curr=NULL;
				}else
					curr=curr->left;
			}else{
				if(!curr->right){
					curr->right=new TreeNode(value);
					curr=NULL;
				}else
					curr=curr->right;
			}
		}
	}
}

void Delete(TreeNode* &root, int value){
	if(!root)
		return;
	if(root->val>value)//find node
		Delete(root->left, value);
	else if(root->val<value)
		Delete(root->right, value);
	else{//no child or only one child
		if(!root->left){
			TreeNode* tmp=root->right;
			delete root;
			root=tmp;
		}else if(!root->right){
			TreeNode* tmp=root->left;
			delete root;
			root=tmp;
		}else{//two children
			TreeNode *tmp = root->right;
			TreeNode *parent = NULL;
			while(tmp->left){//get the smallest one among those are bigger than target
				parent=tmp;
				tmp=tmp->left;
			}
			root->val=tmp->val;
			if(parent)
				Delete(parent->left, parent->left->val);
			else
				Delete(root->right, root->right->val);
		}	
	}
}

void showTree(TreeNode* root){
	queue<TreeNode*> q[2];
	int i=0;
	q[i%2].push(root);
	while(!q[i%2].empty()){
		TreeNode* tmp = q[i%2].front();
		q[i%2].pop();
		if(!tmp)	
			cout<<"# ";
		else{
			q[(i+1)%2].push(tmp->left);
			q[(i+1)%2].push(tmp->right);
			cout<<tmp->val<<" ";
		}

		if(q[i%2].empty()){
			i++;
			cout<<endl;
		}
	}
	cout<<endl;
}

int main(){
	TreeNode* root=NULL;
	showTree(root);
	Insert(root, 20);
	Insert(root, 10);
	Insert(root, 30);
	Insert(root, 5);
	Insert(root, 15);
	Insert(root, 25);
	Insert(root, 35);
	Insert(root, 4);
	Insert(root, 16);
	showTree(root);

	//Delete(root, 5);
	//showTree(root);
	//Delete(root, 15);
	//showTree(root);
	//Delete(root, 25);
	//showTree(root);
	Delete(root, 20);
	showTree(root);
	Delete(root, 100);
	showTree(root);




	return 0;
}
