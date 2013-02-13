/* Given a very large string T, |T| = 10 000 000 chars 
 * a stream of small strings Si
 * check if Si is a subsequence of T ? return true/false
 *
 * number of Si ~ 100 000 000 (strings)
 * |Si| ~ 100 chars
 * 'a' to 'z'
 *
 * T = abcdefg
 * S1 = abc        yes
 * S2 = ag          yes
 * S3 = ga          no
 * S4 = aa          no
 *
 */


#include<iostream>
#include<string>
using namespace std;
bool find_substr(string si, string t){
	int s_len=si.size();
	int t_len=t.size();
	int j=0;

	for(int i=0; i<s_len;i++){
    	while(si[i]!=t[j] && j<t_len)
        	j++;
    	if(j==t_len)
       		return false;
		j++;
	}

	return true;
}

int main(){
	
	string s="1";
	string t="";
	while(s.compare("q")){
		cin>>s;
		cin>>t;
		cout<<find_substr(s,t)<<endl;
	}
	return 0;
}
