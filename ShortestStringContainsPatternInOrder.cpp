/*
Given an input array of integers of size n, and a query array of integers of size k.
Find the smallest window of the input array that contains all the elements of the query array, preserving order.
e.g. 
input abdcabxxxxc abc
output abdc
*/

#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

string shortestString(string &s, string &p){    
    string res = "";
    if(p.length() > s.length() || p.length() == 0 || s.length() == 0)
        return res;
    unordered_map<int, int> s_Map_p;
    int mi = s.length() + 1;

    for(int i = 0 ;i < s.length(); i++){
        for(auto sp = s_Map_p.begin(); sp != s_Map_p.end(); sp++){
            int j = sp->second;//started with sp->first in s, get the next index in p that needs to be mathced
            if(j < p.length() && (p[j] == s[i])){
                sp->second = ++j;
                if(j == p.length() && i - sp->first + 1 < mi){
                    mi = i - sp->first + 1;
                    res = s.substr(sp->first, mi);
                    s_Map_p.erase(sp->first);
                }
            }
        }
        if(s[i] == p[0]){
            s_Map_p[i] = 1;
            if(p.length() == 1)
                return p;
        }
    }
    return res;
}

int main(){
    string p;
    string s;
    while(1){
        cin>>p;
        cin>>s;
        cout<<shortestString(s, p)<<endl;
    }
    return 0;
}
