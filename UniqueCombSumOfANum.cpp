/*
 * Given a number, print all the unique combination of sub sums
 *input a num: 1
 *input a num: 2
 *1 + 1
 *input a num: 3
 *1 + 1 + 1
 *1 + 2
 *input a num: 4
 *1 + 1 + 1 + 1
 *1 + 1 + 2
 *1 + 3
 *2 + 2
 *input a num: 5
 *1 + 1 + 1 + 1 + 1
 *1 + 1 + 1 + 2
 *1 + 1 + 3
 *1 + 2 + 2
 *1 + 4
 *2 + 3
 *input a num: 6
 *1 + 1 + 1 + 1 + 1 + 1
 *1 + 1 + 1 + 1 + 2
 *1 + 1 + 1 + 3
 *1 + 1 + 2 + 2
 *1 + 1 + 4
 *1 + 2 + 3
 *1 + 5
 *2 + 2 + 2
 *2 + 4
 *3 + 3
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string num2str(unsigned int num){
	string s;
	unsigned int val = num%10;
	unsigned int next = num/10;
	if(next!=0){
		s = num2str(next);
	}
	s.push_back('0'+val);
	return s;
}


void unique_comb_sum(vector<string> &res, string cur, int start, int sum){
	if(start > sum){
		if(sum == 0)
			res.push_back(cur);
		return;
	}

	for(int i=start; i<=sum; i++){
		string t;
		if(cur==""){
			if(i == sum)
				return;
			else
				t = num2str(i);
		}else{
			t = cur + " + " + num2str(i);
		}
		unique_comb_sum(res, t, i, sum-i);
	}
}

int main(){
	vector<string> res;
	int a;
	cout<<"input a num: ";
	cin>>a;
	unique_comb_sum(res, "", 1, a);
	for(int i=0; i<res.size(); i++)
		cout<<(res[i])<<endl;

	return 0;

}
