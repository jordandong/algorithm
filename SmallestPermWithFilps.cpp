/* You are given an array of n elements [1,2,....n]. 
 * For example {3,2,1,6,7,4,5}.
 * We create a signature of this array by comparing every consecutive pair
 * of elements. If they increase, write I else write D. 
 * For example for the above array, the signature would be "DDIIDI".
 * The signature thus has a length of N-1. 
 * Now the question is given a signature,
 * compute the lexicographically smallest permutation of [1,2,....n].
 * Write the below function in language of your choice
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> FindSmallestPerm(string signature){
    vector<int> res(signature.size()+1, 0);
	for(int i=0; i<res.size(); i++)
		res[i]=i+1;
	int pos = 0;
	int start = 0;
	while (pos<signature.size()){
		if(signature[pos]=='D'){
			start = pos;
			while (pos<signature.size() && signature[pos] == 'D')
				pos++;
			reverse(res.begin() + start, res.begin()+pos+1);
		}
		else
			pos++;
	}
	return res;
}

int main(){
	cout<<"Input a string (e.g DDDDIIDID:"<<endl;
	string s;
	cin>>s;
	vector<int> res = FindSmallestPerm(s);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
