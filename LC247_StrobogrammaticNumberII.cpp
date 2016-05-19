/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.
For example,
Given n = 2, return ["11","69","88","96"].
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
    vector<string> findStrobogrammatic(int n) { 
        vector<string> strobos;
        if (n & 1)
            strobos = {"0", "1", "8"};
        else
            strobos = {""};
        vector<string> bases = {"00", "11", "88", "69", "96"};
        int m = bases.size(); 
        while (n > 1) {
            n -= 2;
            vector<string> temp;
            for (string strobo : strobos)
                for (int i = (n < 2 ? 1 : 0); i < m; i++) //avoid starting with "0"
                    temp.push_back(bases[i].substr(0, 1) + strobo + bases[i].substr(1));
            strobos = temp;
        }
        return strobos;
    }
};

int main()
{
    Solution sol;
    vector<string> res = sol.findStrobogrammatic(2);
    for (auto &e : res)
        cout<<e<<endl;
    res = sol.findStrobogrammatic(3);
    for (auto &e : res)
        cout<<e<<endl;
    res = sol.findStrobogrammatic(4);
    for (auto &e : res)
        cout<<e<<endl;
    return 0;
}

11
88
69
96
101
808
609
906
111
818
619
916
181
888
689
986
1001
8008
6009
9006
1111
8118
6119
9116
1881
8888
6889
9886
1691
8698
6699
9696
1961
8968
6969
9966
