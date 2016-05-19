/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        vector<int> res(2, -1);
        int start = 0;
        int end = numbers.size() - 1;
        while(start < end){
            int sum = numbers[start] + numbers[end];
            if(sum == target){
                res[0] = start + 1;
                res[1] = end + 1;
                break;
            }
            sum > target ? (end--) : (start++);
        }
        return res;
    }

    vector<int> twoSum2(vector<int> &numbers, int target){
        unordered_map<int, int> mp;
        vector<int> res(2, -1);
        for(int i = 0; i < numbers.size(); i++){
            if(mp.find(numbers[i]) != mp.end()){
                res[0] = mp[numbers[i]] + 1;
                res[1] = i + 1;
                break;
            }else{
                mp[target - numbers[i]] = i;
            }
        }
        return res;
    }
};

int main(){
    vector<int> data;
    vector<int> res;
    int N = 10;
    Solution sol;
    for(int i = 1; i < N; i++){
        data.push_back(i);
    }
    while(1){
        int a;  
        cin>>a;
        res = sol.twoSum(data, a);
        cout<<res[0]<<" "<<res[1]<<endl;
        res = sol.twoSum2(data, a);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}
