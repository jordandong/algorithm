/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
Note:
Because the range might be a large number, the low and high numbers are represented as string.
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
    Solution() {
        mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    }

    void strobogrammaticCount(string temp, int& ans, string& low, string& high, int lo, int hi) {
        if (lo > hi) {
            if ((temp[0] != '0' || temp.length() == 1) && less(low, temp) && less(temp, high))
                ans++;
            return;
        }
        for (auto m : mp) {
            temp[lo] = m.first;
            temp[hi] = m.second;
            if ((lo == hi && m.first == m.second) || lo < hi)
                strobogrammaticCount(temp, ans, low, high, lo + 1, hi - 1);
        }
    }

    bool less(string& s, string& t) {
        int m = s.length(), n = t.length(), i;
        if (m != n)
          return m < n;
        for (i = 0; i < m; i++)
            if (s[i] == t[i])
              continue;
            else
              break;
        return i == m || s[i] < t[i];
    }

    int strobogrammaticInRange(string low, string high) {
        int ans = 0, l = low.length(), u = high.length();
        for (int i = l; i <= u; i++) {
            string temp(i, ' ');
            strobogrammaticCount(temp, ans, low, high, 0, i - 1);
        }
        return ans;
    }
private:
    unordered_map<char, char> mp;
};

int main()
{
    Solution sol;
    cout<<sol.strobogrammaticInRange("50", "100")<<endl;
    return 0;
}

3
