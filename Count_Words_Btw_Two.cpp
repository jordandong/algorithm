/* Given a string of words and two words
 * find how many words between these two words
 * e.g. s = I have a dream that is secret
 *      s1 = have
 *      sw = is
 * output = 3 (a, dream, that)     
 *
 * */

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

int count_words(string &s, string &s1, string &s2){
	size_t pos1 = s.find(s1);
	size_t pos2 = s.find(s2);
	cout<<"pos1="<<pos1<<", pos2="<<pos2<<endl;
	if(pos1==string::npos || pos2==string::npos)
		return 0;
	string sub = s.substr(pos1, pos2-pos1);
	cout<<"sub="<<sub<<endl;
	stringstream ss;
	ss<<sub;
	int res = -1;
	while(ss.peek()!=EOF){
		if(ss.peek()==' '){
			ss.ignore();
			continue;
		}else{
			string t;
			ss>>t;
		    cout<<t<<endl;
			res++;
		}

	}
	return res;
}
int main(){
	string s = "I have a dream that is secret!";
	string s1 = "have";
	string s2 = "is";
	cout<<"counts is "<<count_words(s, s1, s2)<<endl;

	return 0;
}
