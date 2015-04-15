/*
Sort a given Array and make sure the Array to meet a0<=a1>=a2<=a3>=a4.... after sorting
*/

#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int> &data){
    int sz = data.size();
    bool up = false;  
    for(int i = 1; i < sz; i++){
        if((data[i] > data[i - 1]) == up)
            swap(data[i], data[i - 1]);
        up = !up;
    }
}

int main(){
    vector<int> data;
    int N = 10;
    for(int i = 0; i < N; i++)
        data.push_back(i);
    sortArray(data);
    for(int i = 0; i < N; i++)
        cout<<data[i];
    cout<<endl;
    return 1;
}
