/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
Given word1 = "makes", word2 = "coding", return 1. 
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
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
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long dist = INT_MAX, i1 = dist, i2 = -dist;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1)
                i1 = i;
            if (words[i] == word2) {
                if (word1 == word2)
                    i1 = i2;
                i2 = i;
            }
            dist = min(dist, abs(i1 - i2));
        }
        return dist;
    }
};

class Solution {  
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long dist = INT_MAX, i1 = dist, i2 = -dist;
        bool same = word1 == word2;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                i1 = i;
                if (same)
                    swap(i1, i2);
            } else if (words[i] == word2) {
                i2 = i;
            }
            dist = min(dist, abs(i1 - i2));
        }
        return dist;
    }
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
    Solution wordDistance;
    cout<<wordDistance.shortestWordDistance(words, "aa", "dd")<<endl;
    cout<<wordDistance.shortestWordDistance(words, "aa", "cc")<<endl;
    cout<<wordDistance.shortestWordDistance(words, "aa", "aa")<<endl;
    return 0;
    
}

1
2
1


