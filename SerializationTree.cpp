/*Design an algorithm and write code to serialize and deserialize a binary tree.
 *Writing the tree to a file is called "serialization"
 *and reading back from the file to reconstruct the exact same binary tree is "deserialization."
 *Assume we have a binary tree below:
 *
 *    _30_ 
 *   /    \    
 *  10    20
 * /     /  \ 
 *50    45  35
 *Using pre-order traversal, the algorithm should write the following to a file:
 *
 *30 10 50 # # # 20 45 # # 35 # #
 *
 */

#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

class BinaryTree{
	public:
		BinaryTree *left;
		BinaryTree *right;
	        int data;
		BinaryTree(int val){
			data = val;
			left=NULL;
			right=NULL;
		}
		~BinaryTree(){
			if(!left)
				delete left;
			if(!right)
				delete right;
		}
};

void writeBinaryTree(BinaryTree *p, ostream &out) {
	if (!p) {
		out << "# ";
	} else {
		out << p->data << " ";
		writeBinaryTree(p->left, out);
		writeBinaryTree(p->right, out);
	}
}


bool readNextToken(int &token, istream &fin){
	while(fin.peek() == ' ')
		fin.ignore();
	bool isNum = false;
	if(fin.peek()!='#'){
		fin>>token;
		isNum=true;
	}else{
		fin.ignore();
	}
	return isNum;
}

	
void readBinaryTree(BinaryTree* &p, istream &fin) {
	int token;
	if (readNextToken(token, fin)){ 
		p = new BinaryTree(token);
		readBinaryTree(p->left, fin);
		readBinaryTree(p->right, fin);
	}else{
		p = NULL;
	}
}

void printTree(BinaryTree *root){
	queue<BinaryTree*> q1;
	queue<BinaryTree*> q2;
	q1.push(root);
	cout<<endl;
	while(!q1.empty()){
		BinaryTree* t = q1.front();
		q1.pop();
		if(t == NULL)
			cout<<"#   ";
		else{
			cout<<t->data<<"  ";
			q2.push(t->left);
			q2.push(t->right);
		}
		if(q1.empty()){
			cout<<endl;
			swap(q1,q2);
		}
	}
}


int main(){
	BinaryTree* root = new BinaryTree(30);
	root->left = new BinaryTree(10);
	root->right = new BinaryTree(20);
	root->left->left = new BinaryTree(50);
	root->right->left = new BinaryTree(45);
	root->right->right = new BinaryTree(35);

	writeBinaryTree(root, cout);
        
	ifstream fin;
	BinaryTree *r_root = NULL;
	readBinaryTree(r_root, cin);
	printTree(r_root);

	return 0;
}

//*********************************************

void Serialize(TreeNode * node, vector<char> &output)
{
       if(node == NULL){
             output.push_back('#');
             return;
       }

       output.push_back(node->val + '0');
       Serialize(node->left, output);
       Serialize(node->right, output);
}

TreeNode *Deserialize(vector<char> output, int &index)
{
       if(index > output.size() || output[index] == '#') return NULL;

       TreeNode *node = new TreeNode(output[index] -'0');
       index ++;
       node->left = Deserialize(output, index);
       index++;
       node->right = Deserialize(output, index);
       return node;
}
