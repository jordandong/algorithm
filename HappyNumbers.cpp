/*
check if a number is happy number.
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers, while those that do not end in 1 are unhappy numbers (or sad numbers).
http://en.wikipedia.org/wiki/Happy_number
*/

#include <iostream>
#include <set>
using namespace std;

bool is_happy_number(int num){
    if(num <= 0)
        return false;
    set<int> v;
    int next = 0;
    v.insert(num);
    while(num){
        int d = num%10;
        next += d*d;
        num /= 10;
        if(num == 0){
            if(next == 1)
                return true;
            if(v.find(next) != v.end())
                return false;
            num = next;
            v.insert(num);
            next = 0;
        }
    }
}

int main(){
    int cnt = 0;
    for(int i = 0; i <= 1000; i++){
        if(is_happy_number(i)){
            cout<<i<<" ";
            cnt++;
        }
    }
    cout<<endl;
    cout<<"CNT : "<<cnt<<endl;//143 below 1000
    return 0;
}

