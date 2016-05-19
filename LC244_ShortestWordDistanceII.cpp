/*
This is a follow up of Shortest Word Distance. 
The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters.
How would you optimize it?

Design a class which receives a list of words in the constructor,
and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = "coding”, word2 = "practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class WordDistance {
private:
    unordered_map<string, vector<int> > wordInd;
public:
    WordDistance(vector<string> words) {
        int N = words.size();
        for (int i = 0; i < N; i++)
            wordInd[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int> indexes1 = wordInd[word1];
        vector<int> indexes2 = wordInd[word2];
        int m = indexes1.size(), n = indexes2.size();
        int i = 0, j = 0, dist = INT_MAX;
        while (i < m && j < n) {
            dist = min(dist, abs(indexes1[i] - indexes2[j]));
            if (indexes1[i] < indexes2[j])
                i++;
            else
                j++;
        }
        return dist;
    }
};
// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

int main()
{
    vector<string> words;
    words.push_back("aa");
    words.push_back("bb");
    words.push_back("cc");
    words.push_back("dd");
    words.push_back("aa");
    words.push_back("aa");
    WordDistance wordDistance(words);
    cout<<wordDistance.shortest("aa", "dd")<<endl;
    cout<<wordDistance.shortest("aa", "cc")<<endl;
    return 0;
}

1
2


