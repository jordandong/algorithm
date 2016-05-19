/*Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/

#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    void reverseWords(string &s){
        reverse(s.begin(), s.end());
        for(int i = 0, j = 0; j <= s.size(); j++){
            if(j == s.size() || s[j] == ' '){
                reverse(s.begin() + i, s.begin() + j);
                i =  j + 1;
            }
        }
    }
};


int main(){
    string s;
    Solution sol;  
    s = "My Name is You Guess";
    sol.reverseWords(s);
    cout<<s<<endl;
    s = " My Name is You Guess";
    sol.reverseWords(s);
    cout<<s<<endl;
    s = "My Name is You Guess ";
    sol.reverseWords(s);
    cout<<s<<endl;
    s = "My Name is    You Guess";
    sol.reverseWords(s);
    cout<<s<<endl;
    return 0;
}
