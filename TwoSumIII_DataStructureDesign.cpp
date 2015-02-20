#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class TwoSum{
private:
    unordered_map<int, int> mp;
public:
    void add(int num){
        if(mp.find(num) != mp.end())
            mp[num]++;
        else
            mp[num] = 1;
    }

    bool find(int val){
        for(auto it = mp.begin(); it != mp.end(); it++){
            int v = val - it->first;
            if(v == it->first)
                return it->second > 1;
            if(mp.find(v) != mp.end())
                return true;
        }
        return false;
    }
};

int main(){
    TwoSum ts;
    while(1){
        int a;  
        cin>>a;
        ts.add(a);
        cin>>a;
        ts.add(a);
        cin>>a;
        cout<<ts.find(a)<<endl;
    }
    return 0;
}
