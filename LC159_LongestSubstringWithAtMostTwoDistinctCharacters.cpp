/*
   Given a string S, find the length of the longest substring T that contains at most two distinct characters.
    For example,
    Given S = "eceba"
    T is "ece" which its length is 3.
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s){
        int l = 0, r = 0;
        int end_of_first = -1;
        int mx = 0;
        for(r = 1; r < s.length(); r++) {
            if(s[r] == s[r - 1])
                continue;
            if (end_of_first >= 0 && s[r] != s[end_of_first]) {
                mx = max(mx, r - l);
                l = end_of_first + 1; 
            }
            end_of_first = r - 1;  
        }
        return max(r - l, mx);
    }
  
    int lengthOfLongestSubstringKDistinct(string s, int k){
        int l = 0, r = 0;
        int mp[256];
        int mx = 0;
        int cnt = 0;
        memset(mp, 0, sizeof(int)*256);

        for(r = 0; r < s.length(); r++) {
            if(mp[s[r]] == 0)
                cnt++;
            mp[s[r]]++;
            while(cnt > k){
                if(--mp[s[l++]] == 0)
                    cnt--;
            }
            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};

int main(){
    string s;
    Solution sol;
    int k = 0;
    cin>>k;
    while(1){
        cin>>s;
        cout<<"len : "<<sol.lengthOfLongestSubstringTwoDistinct(s)<<endl;
        cout<<"lenk : "<<sol.lengthOfLongestSubstringKDistinct(s, k)<<endl;
    }
    return 0;
}
