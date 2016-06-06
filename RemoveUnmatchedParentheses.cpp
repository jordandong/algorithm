/*
given a string, remove all the unmatched parentheses, keep the longest string with matched parentheses
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeUnmatchedParentheses(string s) {
        string res = "";
        int l = 0, r = 0, N = s.size();
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                l++;
            } else if (s[i] == ')') {
                if (l > 0) {
                    l--;
                } else {
                    s[i] = '#';
                }
            }
        }
        l = 0;
        r = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (s[i] == ')') {
                r++;
            } else if (s[i] == '(') {
                if (r > 0) {
                    r--;
                } else {
                    s[i] = '#';
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (s[i] != '#')
                res.push_back(s[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;  
    cout<<sol.removeUnmatchedParentheses("a(()())bsbd)((")<<endl;
    cout<<sol.removeUnmatchedParentheses("")<<endl;
    cout<<sol.removeUnmatchedParentheses(")))(a)(b)(((")<<endl;
    cout<<sol.removeUnmatchedParentheses("(a)(((b)(((v)))")<<endl;
    cout<<sol.removeUnmatchedParentheses(")))))ddd((((((")<<endl;
    cout<<sol.removeUnmatchedParentheses("a)()()(b((((((")<<endl;
    cout<<sol.removeUnmatchedParentheses("(a)))))))(df)))))")<<endl;
    return 0;
}

a(()())bsbd

(a)(b)
(a)(b)(((v)))
ddd
a()()b
(a)(df)
