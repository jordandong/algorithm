/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd".
We can keep "shifting" which forms the sequence:  "abc" -> "bcd" -> ... -> "xyz" 
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
For example,
given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Return:  [   ["abc","bcd","xyz"],   ["az","ba"],   ["acef"],   ["a","z"] ] 

Note: For the return value, each inner list's elements must follow the lexicographic order.
*/

/*
["eqdf", "qcpr"]。
((‘q’ - 'e') + 26) % 26 = 12, ((‘d’ - 'q') + 26) % 26 = 13, ((‘f’ - 'd') + 26) % 26 = 2
((‘c’ - 'q') + 26) % 26 = 12, ((‘p’ - 'c') + 26) % 26 = 13, ((‘r’ - 'p') + 26) % 26 = 2
"eqdf" and "qcpr" are group shifted strings
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mp;
        for (auto &s : strings) {
            string key = "";
            for (auto &c : s)
                key += to_string(((c - s[0]) + 26) % 26) + " ";
            mp[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto &e : mp) {
            sort(e.second.begin(), e.second.end());
            result.push_back(e.second);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> strings;
    strings.push_back("abc");
    strings.push_back("bcd");
    strings.push_back("cde");
    strings.push_back("a");
    strings.push_back("d");
    strings.push_back("x");
    vector<vector<string>> res = sol.groupStrings(strings);
    for (auto e : res) {
        for (auto r : e) {
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}

a d x 
abc bcd cde 
