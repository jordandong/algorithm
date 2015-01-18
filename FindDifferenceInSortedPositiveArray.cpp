/*
Given a sorted positive array, find two elements and the difference of these two elements equals to a constant C.
Requirment O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> FindDifference(vector<int> &data, int C){
    int i = 0;
    int j = 0;
    int sz = data.size();
    vector<int> res;
    if(C < 0)
        C = -C;
    while(i < sz && j < sz){
        if(i == j){
            j = i + 1;
        }else if(data[j] - data[i] > C){
            i++;
        }else if(data[j] - data[i] < C){
            j++;
        }else{
            res.push_back(i);
            res.push_back(j);
            break;   
        }
    }
    return res;
}

int main(){
    int n = 20;
    vector<int> data;
    int base = 1;
    int C = 0;
    vector<int> res;
    for(int i = 0; i < n; i++){
        data.push_back(base);
        base<<=1;
    }
    cout<<"input C:";
    cin>>C;
    res = FindDifference(data, C);
    cout<<"From index "<<res[0]<<" value "<<data[res[0]]<<" to index "<<res[1]<<" value "<<data[res[1]]<<endl;
}
