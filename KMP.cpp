/*
  Find a sting p in a string s,
  if found , return the pos
  if not, return -1
*/


#include <iostream>
#include <string>
using namespace std;

void cal_next(int *next, string p){
	int len = p.length();
	int k = -1;
	int j = 0;
	next[0] = -1;
	while(j < len - 1){
		if(k == -1 || p[j] == p [k]){
			next[++j] = ++k;
		}else{
			k = next[k];
		}
	}
}

int KMP(string s, string p){
	int ls = s.length();
	int lp = p.length();
	int si = 0;
	int pi = 0;
	int *next = new int[lp];
	cal_next(next, p);
	while(si < ls && pi < lp){
		if(pi == -1 || s[si] == p[pi]){
			si++;
			pi++;
		}else{
			pi = next[pi];
		}
	}
	delete next;

	return (pi == lp)?(si - pi):-1;
}

int main(){
	string p, s;
	cin>>p;
	cin>>s;
	//p = "abacdababx";
	//s = "swqewqrrabacdababxtooipzxcipxzc";
	cout<<KMP(s, p)<<endl;
	return 0;
}
