/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic. The number is represented as a string.
For example, the numbers "69", "88", and "818" are all strobogrammatic.
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
    bool isStrobogrammatic(string num) {
        int n = num.length(); 
        for (int l = 0, r = n - 1; l <= r; l++, r--)
            if (lookup.find(num[l]) == lookup.end() || lookup[num[l]] != num[r])
                return false;
        return true;
    }
private:
    unordered_map<char, char> lookup{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
};

int main()
{
    vector<string> words;
    words.push_back("aa");
    words.push_back("bb");
    words.push_back("cc");
    words.push_back("dd");
    words.push_back("aa");
    words.push_back("aa");
    Solution sol;
    cout<<sol.isStrobogrammatic("121")<<endl;
    cout<<sol.isStrobogrammatic("122")<<endl;
    cout<<sol.isStrobogrammatic("181")<<endl;
    cout<<sol.isStrobogrammatic("8698")<<endl;
    return 0;
}

0
0
1
1
