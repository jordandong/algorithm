/*
The problem is to find the minimum number of squares required to sum to a number n.

Some examples:
min[1] = 1 = 1^2
min[2] = 2 = 1^2 + 1^2
min[4] = 1 = 2^2
min[13] = 2 = 3^2 + 2^2

Four-square theorem that says that any natural number can be represented as the sum of four squares.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findSquaredList(int n){
    vector<int> mi(n + 1, 100);
    vector<int> num(n + 1, -1);
    mi[0] = 0;  
    for(int i = 1; i <= n; i++){
        for(int j = 1; j*j <= i; j++){
            if(mi[i] >= mi[i - j*j] + 1){
                mi[i] = mi[i - j*j] + 1;
                num[i] = j;
            }
        }
    }
    int idx = n;
    vector<int> res;  
    while(n > 0){
        res.push_back(num[n]);
        n -= num[n]*num[n];
    }
    //return mi[n];
    return res;
}

int main(){
    for(int i = 1; i <= 13; i++){ 
        //cout<<i<<" : "<<findSquaredList(i)<<endl;
        vector<int> res = findSquaredList(i);
        printf("n = %d, --> ", i);
        for(int j = 0; j < res.size(); j++){
            printf("%d*%d(%d) ", res[j], res[j], res[j]*res[j]);
        }
        printf("\n");
    }
    return 0;  
}
