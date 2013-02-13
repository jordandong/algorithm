/*
 * find the longest commom substring which is continus
 *e.g
 *input abcdxayazazayaxa  abcdxyzzyx
 *output abcd
 */

#include<iostream>
#include<string>
using namespace std;

string LCS_Fixed(string &s1,string &s2){
	int ls1 = s1.length();
	int ls2 = s2.length();
	//if null, no results.
	if(ls1==0||ls2==0)
		return "";
	//array store length info
	int c[ls2];
	cout<<"s1 is "<<ls1<<", s2 is "<<ls2<<endl;
	int max,maxj,i,j;
	maxj=0;max=0;
	for(i=0;i<=ls1-1;i++){//from beginning
		for(j=ls2-1;j>=0;j--){//from end in order to apply the previous results from the last char
			if(s1.at(i)==s2.at(j)){
				if(i==0||j==0)
					c[j]=1;//edge pos, set 1 if equal
				else
					c[j]=c[j-1]+1;//based on the last results from the previous char, update current result
			}
			else{
				c[j]=0;//not equal
			}
			if(c[j]>max){//marked the max every time to avoid clear the result
				max=c[j];
				maxj=j;
			}
		}
	}
	//output
	if(max==0)
		return "";
	return s2.substr(maxj-max+1, max);
}

int main(){
	string a;
	string b;
	cin>>a>>b;
	cout<<LCS_Fixed(a,b)<<endl;
	return 0;
}
