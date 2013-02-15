/*find the lowest common ancestor of two nodes in a tree
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

TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b, int &count){
	if(!root)
		return NULL;
	if(root->val==a->val&&root->val==b->val){
		count=2;
		return root;
	}
	TreeNode* x = LowestCommonAncestor(root->left, a, b, count);
	if(x&&x->val!=a->val&&x->val!=b->val)
		return x;
	TreeNode* y = LowestCommonAncestor(root->right, a, b, count);
	if(y&&y->val!=a->val&&y->val!=b->val)
		return y;

	if(x&&y)
		return root;
	else if(root->val==a->val||root->val==b->val){
		cout<<"found"<<endl;
		count++;
		return root;
	}else
		return !x?y:x;
}

TreeNode* Helper(TreeNode* root, TreeNode* a, TreeNode* b){
	int count=0;
	TreeNode* res = LowestCommonAncestor(root, a, b, count);
	return count==2?res:NULL;
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

	TreeNode* a = new TreeNode(10);
	TreeNode* b = new TreeNode(10);

	TreeNode* res = Helper(root, a, b);
	if(res)
		cout<<res->val<<endl;
	else
		cout<<"not found"<<endl;

	return 0;
}
