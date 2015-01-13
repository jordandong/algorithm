/*
Given a string, it may be composed by repeating a string whose length is >=2. The repeating time is more than 1.
Return if s is composed by such a small string.
e.g
aaaaaa -> true
abaabc -> true
abc->false
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isMultiple(string s){
    int l = s.length();
    if(l <=3)
        return false;  
	
    int p_cur = 0; //from 0 to p_end is the repeat pattern
    int p_end = 0;
    int p_rpt = 1;
    while(p_rpt < l){
        if(s[p_rpt] == s[p_cur]){
            p_rpt++;
            p_cur++;
            if(p_cur>p_end)
                p_cur = 0;
        }else{
            if(p_cur == 0){//if it is the first one that doesn't match, include current p_prt. 
                p_end = p_rpt;
                p_rpt++;
            }else{//if  it is not the first one that doesn't match, include all the previous ones.
                p_end = p_rpt-1;    
                p_cur=0;
            }
        }
    }

    if(p_end == 0){ //if pattern len is one
        if(l%2 == 0)
            return true;	
        for(int base = 3; base*base<l; base+=2){
            if(l%base == 0)
                return true;
        }
        return false;
    }else if(p_end == l-1){//if pattern len is string length
        return false;   
    }else if(p_cur == 0){//matched
        return true;
    }else{//dosen't match
        return false;   
    }
}

/*
Given String S of length n. Return false if n < 4.
Let T = S.substring(1) + S.substring(0,n-1), return true if S is substring 
of T
If "aaaaaaaaaa" is False, then return T.indexOf(S) > 0
*/
bool isMultiple1(string s){
    static const size_t npos = -1;
    int l = s.length();
    if(l <=3)
        return false;
 
    string s1 = s.substr(1, l-1);
    string s2 = s.substr(0, l-1);
    string s3 = s1 + s2;
    size_t sz = s3.find(s);
    if(sz == 0){
        if(l%2 == 0)
            return true;	
        for(int base = 3; base*base<l; base+=2){
            if(l%base == 0)
                return true;
        }
        return false; 
    }else if(sz == npos)
        return false;
    else
        return true;   
}


int main(){
    vector<string> input;
    input.push_back("abcabcabcab");
    input.push_back("false");
    input.push_back("bcdbcdbcde");
    input.push_back("false");
    input.push_back("abcdabcd");
    input.push_back("true");
    input.push_back("xyzxy");
    input.push_back("false");
    input.push_back("aaaaaaaaaaaaaaaaaaaaa");
    input.push_back("true");
    input.push_back("aaaaaaaaaaa");
    input.push_back("false");
    input.push_back("aaaaaa");
    input.push_back("true");
    input.push_back("bcdbcdbcdbcdbcdbc");
    input.push_back("false");
    input.push_back("aaaaabaaaa");
    input.push_back("false");
    input.push_back("bcdbcdbcdebcdbcdbcde");
    input.push_back("true");
    input.push_back("abcababcab");
    input.push_back("true");
    input.push_back("abc");
    input.push_back("false");
    input.push_back("abcabcabcdabcabcabcde");
    input.push_back("false");
    input.push_back("abcabcabc");
    input.push_back("true");
    input.push_back("bcdbcdbcdebcdbcdbcde");
    input.push_back("true");
    input.push_back("abaaba");
    input.push_back("true");
    input.push_back("ababcababc");
    input.push_back("true");
    input.push_back("abaaaaaaaaba");
    input.push_back("false");
    input.push_back("abaaaaaaaaaba");
    input.push_back("false");
    input.push_back("abaabaaba");
    input.push_back("true");

    for(int i = 0; i<input.size(); i+=2){
        cout<<input[i+1]<<(isMultiple(input[i])?"->true ":"->false ")<<input[i]<<endl;
    }
    cout<<endl<<endl;
    for(int i = 0; i<input.size(); i+=2){
        cout<<input[i+1]<<(isMultiple1(input[i])?"->true ":"->false ")<<input[i]<<endl;
    }

    return 0;	
}
