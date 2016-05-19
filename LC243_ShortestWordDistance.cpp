/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = "coding", word2 = "practice", return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int N = words.size();
        int idx1 = -1, idx2 = -1, dist = N;
        for (int i = 0; i < N; i++) {
            if (words[i] == word1)
              idx1 = i;
            else if (words[i] == word2)
              idx2 = i;
            if (idx1 != -1 && idx2 != -1)
                dist = min(dist, abs(idx1 - idx2));
        }
        return dist;
    }
};

int main()
{
    vector<string> data;
    data.push_back("aa");
    data.push_back("bb");
    data.push_back("cc");
    data.push_back("dd");
    data.push_back("aa");
    data.push_back("aa");
    Solution sol;
    cout<<sol.shortestDistance(data, "aa", "dd")<<endl;
    cout<<sol.shortestDistance(data, "aa", "cc")<<endl;
    return 0;
    
}

1
2
