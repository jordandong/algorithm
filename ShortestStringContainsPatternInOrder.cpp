/*
Given an input array of integers of size n, and a query array of integers of size k.
Find the smallest window of the input array that contains all the elements of the query array, preserving order.
e.g. 
input abdcabxxxxc abc
output abcdc
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
    vector<int> s_firstIdx;
    int mi = s.length() + 1;

    for(int i = 0 ;i < s.length(); i++){
        for(int s_f_id : s_firstIdx){
            int j = s_Map_p[s_f_id];//started with s_d_id, get the next index in p that needs to be mathced
            if( j < p.length() && (p[j] == s[i])){
                s_Map_p[s_f_id] = ++j;
                if(j == p.length() && i - s_f_id + 1 < mi){
                    //may delete s_f_id at s_firstIdx and [s_f_id, j] at s_Map_p since no more better than this	
                    mi = i - s_f_id + 1;
                    res = s.substr(s_f_id, mi);
                }
            }
        }
        if(s[i] == p[0]){
            s_firstIdx.push_back(i);
            s_Map_p[i] = 1;
        }
    }
    return res;
}

int main(){
    string p = "abc";
    string s;
    while(1){
        cin>>s;
        cout<<shortestString(s, p)<<endl;
    }
    return 0;
}
