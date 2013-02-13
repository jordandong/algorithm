/*
 * Given a string s, return the shortest substring that is only
 * occurring once.
 *
 * Examples:
 *
 * s="aabbabbaab" retunrs either "bab" or "baa"
 *
 * s="aaaa" returns "aaaa"
 */


#include<iostream>
#include<string>
using namespace std;

class Node{
public:
	Node* root[26];
	int counter;
	Node(){
		for(int i=0;i<26;i++)
			root[i]=NULL;
		counter=0;
	}

	void add(string s, int i){
		counter++;
		if(i==s.length())
			return;
		int index = s[i]-'a';
		if(root[index]==NULL)
			root[index]=new Node();
		root[index]->add(s, i+1);
	}
};


void dfs(Node *n, string tmp, string &res){
	if(n==NULL||tmp.size()>=res.size())
		return;
	if(n->counter==1){
		res=tmp;
		return;
	}
	
	for(int i=0; i<26;i++){
		if(n->root[i]!=NULL){
			tmp.push_back('a'+i);
			dfs(n->root[i],tmp, res);
			tmp.erase(tmp.size()-1);
		}
	}
}


int main(){
	string s;
	cin>>s;
	Node *root = new Node();
	for(int i=0; i<s.size();i++)
		root->add(s, i);
	string res=s;
	dfs(root, "", res);

	cout<<res<<endl;
}
