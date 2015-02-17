/*
Gvien a array, find out the pairs which meets A[i] > A[j] AND i < j
e.g.
4 3 2 1
should return
6 which means (4 3) (4 2) (4 1) (3 2) (3 1) (2 1)
*/

#include<iostream>
#include<vector>
using namespace std;

//T: O(NlogN)
vector<int> revertPair(vector<int> &data, int start, int end, int &res){
    vector<int> p;
    if(start == end){
        p.push_back(data[start]);
        return p;
    }
    int mid = start + (end - start)/2;
    vector<int> p1 = revertPair(data, start, mid, res);
    vector<int> p2 = revertPair(data, mid + 1, end, res);
    int sz1 = p1.size();
    int sz2 = p2.size();
    int i = 0;
    int j = 0;
    while(i < sz1 && j < sz2){
        if(p1[i] <= p2[j]){
            p.push_back(p1[i]);
            i++;
        }else{
            p.push_back(p2[j]);
            res += (sz2 - i); //if p1[i] is bigger, then p1[i] to p1[sz1 - 1] are bigger
            j++;
        }
    }
    
    while(i < sz1)
        p.push_back(p1[i++]);
    while(j < sz2)
        p.push_back(p2[j++]);
    return p;
}

int main(){
    vector<int> data, res;
    int count = 0;
    int sz = 8;
    for(int i = sz; i >0; i--)
        data.push_back(i);
    res = revertPair(data, 0, sz - 1, count); 
    cout<<"Pairs : "<<count<<endl;
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
