/*
Given a array, saying count-array,
the value at pos i in count-array means the number of elemnets those are after pos i and less than the value at pos i in original array.
Original array is from 1 to N. Restore original array.
e.g.
count-array : 3 0 1 0
original array : 4 1 3 2
O(nlogn) is required.
*/

#include<iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    TreeNode* left;
    TreeNode* right;
    int start;
    int end;
    int numOfleft;
    TreeNode(int s, int e, int num){
        start = s;
        end = e;
        numOfleft = num;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildBST(int s, int e){
    TreeNode* node = NULL;
    if(s == e){
        node = new TreeNode(s, e, 0); // leaf node represents one element
        return node;
    }

    int m = s + (e - s)/2;
    node = new TreeNode(s, e, m - s + 1);
    node->left = buildBST(s, m);
    node->right = buildBST(m + 1, e);
}

int updBST(TreeNode* root, int k){ // find kth smallest element
    if(k == 1 && root->end == root->start)
        return root->start;
    if(k <= root->numOfleft){
        (root->numOfleft)--; //update the letf child nums
        return updBST(root->left, k);    
    }else{
        return updBST(root->right, k - root->numOfleft);   
    }
}

int main(){
    TreeNode *root = NULL;
    int n = 10;
    root = buildBST(1,n);
    vector<int> input;
    input.push_back(3);
    input.push_back(0);
    input.push_back(1);
    input.push_back(0);

    for(int i = 0; i < input.size(); i++)
        cout<<updBST(root, input[i]+1)<<endl;

    return 0;
}
