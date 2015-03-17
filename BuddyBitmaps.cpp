/*
given a completed tree and the num of the leaves.
the node is set to true only when all the child nodes below it are set to true.
implement set and clear leaf node func
*/
#include <iostream>
#include <queue>
using namespace std;

class Node{
public:	
    Node* l;
    Node* r;
    bool val;
    Node(){l = NULL; r = NULL; val = false;}
};

void BitsHelper(Node* root, int offset, int len, bool is_set){
    if(len <= 1){
        if(len == 1)
            root->val = is_set;
       return;
    }
    if(offset < len/2)
        BitsHelper(root->l, offset, len/2, is_set);
    else
        BitsHelper(root->r, offset - len/2, len/2, is_set);
    if(root->l->val == is_set && root->r->val == is_set)
        root->val = is_set;
    return;
}

void setBit(Node* root, int offset, int len){
    BitsHelper(root, offset, len, true);
}

void clearBit(Node* root, int offset, int len){
    BitsHelper(root, offset, len, false);
}

void printTree(Node* root){
    queue<Node*> q[2];
    int c = 0;
    q[c].push(root);
    while(q[c%2].size()){
        Node* t = q[c%2].front();
        q[c%2].pop();
        if(!t)
            continue;
        cout<<t->val;
        q[(c+1)%2].push(t->l);
        q[(c+1)%2].push(t->r);
        if(q[c%2].empty()){
            c++;
            cout<<endl;
        }
    }
    cout<<endl;
}

int main(){
    queue<Node*> q[2];
    int c = 0;
    Node* root = new Node();
    q[c].push(root);
    while(q[c%2].size()){
        Node* t = q[c%2].front();
        q[c%2].pop();
        t->l = new Node();
        t->r = new Node();
        if(c < 2){
            q[(c+1)%2].push(t->l);
            q[(c+1)%2].push(t->r);
        }
        if(q[c%2].empty())
            c++;
    }

    setBit(root, 0, 8);
    printTree(root);
    setBit(root, 1, 8);
    printTree(root);
    setBit(root, 3, 8);
    printTree(root);
    setBit(root, 5, 8);
    printTree(root);
    setBit(root, 7, 8);
    printTree(root);
    setBit(root, 2, 8);
    printTree(root);
    setBit(root, 4, 8);
    printTree(root);
    setBit(root, 6, 8);
    printTree(root);

    clearBit(root, 3, 8);
    printTree(root);
    clearBit(root, 4, 8);
    printTree(root);
    clearBit(root, 5, 8);
    printTree(root);
    clearBit(root, 0, 8);
    printTree(root);
    clearBit(root, 2, 8);
    printTree(root);
    clearBit(root, 1, 8);
    printTree(root);
    clearBit(root, 6, 8);
    printTree(root);
    clearBit(root, 7, 8);
    printTree(root);

    return 0;
}
