/*
Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return ["2", "4->49", "51->74", "76->99"]
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int> vals, int start, int end) {
        vector<string> res;
        int exp = start;
        int miss_start = start - 1;
        int miss_end = start - 1;

        for(int i = 0; i < vals.size(); i++){
            if(vals[i] == exp){
                exp++;
            }else{
                miss_start = exp;
                miss_end = min(vals[i] - 1, end);
                if(miss_start == miss_end)
                    res.push_back(int_to_string(miss_start));	
                else
                    res.push_back(int_to_string(miss_start) + "->" + int_to_string(miss_end));	
                exp = vals[i] + 1;
                if(vals[i] > end)
                    break;	
            }
        }
        if(exp == end)
           res.push_back(int_to_string(exp));	
        else if (exp < end)
           res.push_back(int_to_string(exp) + "->" + int_to_string(end));	

        return res;
    }

    string int_to_string(int val){
        string s;
        do{
            char t = (char)(val%10 + '0');
            s.append(1, t);
            val /= 10;
        }while(val);
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(){
    int r_s = 0;
    int r_e = 100;
    vector<int> data;
    int N = 5;
    for(int i = 0; i < N; i++){
        int v;
        cin>>v;
        data.push_back(v);
    }
    Solution sol;
    vector<string> res = sol.findMissingRanges(data, r_s, r_e);
    for(int i = 0; i < N; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 1;
}
