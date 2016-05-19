/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int M = s.length();
        int N = t.length();
        if(M > N)
            return isOneEditDistance(t, s);
        if(N - M > 1)
            return false;
        int i = 0;
        int j = 0;
        while(i < M && s[i] == t[j]){
            i++;
            j++;
        }

        if(i == M)
            return M != N;

        j++;
        if(M == N)
            i++;
  
        while(i < M && s[i] == t[j]){
            i++;
            j++;
        }
        return i == M;
    }
};

int main(){
    vector<string> data;
    int N = 10;
    Solution sol;
    for(int i = 0; i < N; i++){
        string s;
        cin>>s;
        data.push_back(s);
    }
    for(int i = 1; i < N; i++)
        cout<<data[i-1]<<"<-1->"<<data[i]<<"="<<sol.isOneEditDistance(data[i-1], data[i])<<endl;
    return 1;
}
