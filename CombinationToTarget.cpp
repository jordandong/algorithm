//有一个int类型的不重复的数组，还有一个target number，从数组中任意取出数字相加，要求出有多少种方法可以得到这个target。比如数组{1，2}，target是5，可以是1+1+1+1+1，也可以是1+2+2等等

#include<iostream>
#include<vector>
using namespace std;

int PossibleNum(vector<int> &data, int target){
	int N = data.size();
	int dp[target+1];

	dp[0] = 1;
	for(int i=1; i<=target; i++)
		dp[i]=0;

	for(int i=0; i<N; i++){
		for(int j=data[i]; j<=target; j++){
			dp[j] = dp[j-data[i]]+dp[j];
		}
	}

	return dp[target];
}

int main(){
	vector<int> data;
	data.push_back(1);
	data.push_back(2);

	cout<<PossibleNum(data, 10)<<endl;
	return 0;

}
