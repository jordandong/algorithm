//give a array of pair like [(1,2) (6, 20) (5, 10) (2, 20) (3, 30)]
//find the maximum sum of subsequence which is with increasing order
//e.g. 	intput [(1,2) (6, 20) (5, 10) (2, 20) (3, 30)]
//		output 52	-	[(1,2) (2, 20) (3, 30)]

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int DP(vector<pair<int,int> > data){
	int N = data.size();
	int sum = INT_MIN;
	int dp[N];
	for(int i=0; i<N; i++)
		dp[i] = data[i].second;
	for(int i=1; i<N; i++){
		for(int j=i-1; j>=0; j--){
			if(data[i].first>data[j].first)
				dp[i]=max(dp[i], dp[j]+data[i].second);
			sum=max(sum, dp[i]);
		}
	}
	return sum;
}


int main(){
	int n = 1;
	vector<pair<int,int> > data;
	while(n!=0){
		cout<<"size of array:"<<endl;
		cin>>n;
		int i=0;
		while(i<n*2){
			if(i<n){
				data.push_back(make_pair(0,0));
				cin>>data[i].first;
			}
			else{
				cin>>data[i%n].second;
			}
			i++;
		}
		cout<<DP(data)<<endl;
		data.clear();
	}
	return 0;
}
