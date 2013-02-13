/*find the longest sorted substring from a string
 *eg. 	input	19283456
 *		output 	123456
*/
#include<iostream>
#include<string>
using namespace std;

int find_lss(string str){
	int len = 1;
	int end = 0;//current substring end pos
	//no string
	if(str.length()==0)
		return 0;
	cout<<str.length()<<endl;


	for(int i=0;i<str.length();i++){
		cout<<"At char pos:"<<i+1<<endl;
		//if next element is bigger than the value of current end pos
		//add the bigger element after the end pos and reset end pos
		//add length
		if(str.at(i)>str.at(end)){
			str.replace(++end,1,str.substr(i,1));
			len++;
			cout<<"replaced end:"<<end+1<<endl;
		}
		//if next element is smaller than the value of current end pos
		//find the last element which is bigger than this element
		//on the left of end pos and replace it
		//which introduces more possibility to get longer sunstring
		else if(str.at(i)<str.at(end)){
			int k =0;
			for(k =end-1; k>=0;k--){
				cout<<"before end at pos:"<<k+1<<endl;
				if(str.at(i)>str.at(k)){
					str.replace(k+1,1,str.substr(i,1));
					cout<<"replaced char befor end: "<<k+1+1<<endl;
					break;
				}
				else if(k==0){
					str.replace(k,1,str.substr(i,1));
					cout<<"replaced char at the beginning"<<endl;
				}
			}
			if(end==0){
				str.replace(end,1,str.substr(i,1));
				cout<<"replaced char at the beginning"<<endl;
			}
		}
	}
	return len;
}




int main(){
	string a;
	cout<<"Please input a string with number 0-9:"<<endl;
	cin>>a;
	int res = find_lss(a);
	cout<<"The length of the longest increasing substring is "<<res<<endl;
	return 0;
}
