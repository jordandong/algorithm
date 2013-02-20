/*
 *big number add op
 *e.g
 *input: "12345", -"12345"
 *output: "0"
 */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

string op1(string s1, string s2){
	int n1=s1.length()-1;
	int n2=s2.length()-1;
	int n=max(n1,n2)+1;
	string res = string(n+1,'0');
	int carry = 0;
	while(n1>=0||n2>=0){
		char c1=n1>=0?s1[n1]:'0';
		char c2=n2>=0?s2[n2]:'0';
		int tmp = (c1-'0') + (c2-'0') + carry;
		res[n]=tmp%10+'0';
		carry=tmp/10;
		n1--;
		n2--;
		n--;
	}
	if(carry)
		res[n]='1';
	return res[0]=='0'?res.substr(1):res;
}


string op2(string s1, string s2){
	bool neg=false;
	int n1=s1.length()-1;
	int n2=s2.length()-1;
	int n=max(n1,n2);
	int m=n;
	vector<int> res(n+1,0);
	while(n1>=0||n2>=0){
		char c1=n1>=0?s1[n1]:'0';
		char c2=n2>=0?s2[n2]:'0';
		res[n] = (c1-'0') - (c2-'0');
		if(res[n]<0)
			neg=true;
		else if(res[n]>0)
			neg=false;
		n1--;
		n2--;
		n--;
	}

	if(neg){
		int i=m;
		int carry=0;
		while(i>=0){
			if(res[i]>0){
				res[i]+=(-10+carry);
				carry=1;
				i--;
			}
			else{
				res[i]+=carry;
				carry=0;
				if(res[i]<=0)
					i--;
			}
		}
	}else{
		int i=m;
		int carry=0;
		while(i>=0){
			if(res[i]<0){
				res[i]+=(10-carry);
				carry=1;
				i--;
			}
			else{
				res[i]-=carry;
				carry=0;
				if(res[i]>=0)
					i--;
			}
		}
	}
	
	string rtn="";
	bool bg=false;
	for(int i=0;i<=m;i++){
		if(res[i]==0&&!bg)
			continue;
		else{
			bg=true;
			rtn+=abs(res[i])+'0';
		}
	}

	return neg?"-"+rtn:rtn;
}

string add(string s1, string s2){
	bool neg1=s1[0]=='-'?true:false;
	bool neg2=s2[0]=='-'?true:false;
	int m=0;
	int n=0;
	int k=0;
	if(neg1&&neg2){
		string res = op1(s1.substr(1),s2.substr(1));
		return "-"+res;
	}else if(!neg1&&!neg2){
		string res = op1(s1, s2);
		return res;
	}else if(neg1&&!neg2){
		string res = op2(s2, s1.substr(1));
		return res;
	}else{
		string res = op2(s1, s2.substr(1));
		return res;
	}
}

int main(){
	string s1="a";
	string s2="a";
	while(s1[0]!='q'){
		cin>>s1;
		cin>>s2;
		cout<<add(s1,s2)<<endl;
	}
	
	return 0;
}

