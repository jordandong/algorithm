//You have a set of n integers each in the range 0 ... K. Partition these integers into two subsets such that you minimize |S1 - S2|, where S1 and S2 denote the sums of the elements in each of the two subsets.

#include<iostream>
#include<float.h>
#include<vector>
using namespace std;

double BP(vector<int> data){
	int N = data.size();
	int SUM = 0;
	for(int i=0;i<N;i++)
		SUM+=data[i]; //total sum, if there is nega input, convert it to positive first
	int dp[SUM+1];
	dp[0]=1;
	for(int i=1; i<=SUM;i++){
		if(i==data[0])
			dp[i]=1; //dp[i] means there is a sunset whose sum is i
		else
			dp[i]=0;
	}
	
	for(int i=1;i<N;i++){
		for(int j=SUM;j>=data[i];j--){
			dp[j]=max(dp[j], dp[j-data[i]]); 
			//for a new element,
			//dp[j] is true if dp[j] for the last element is true 
			//or dp[j-data[i]] is true
		}
	}

	double S = SUM/2.0; //best partition
	double res=DBL_MAX;
	for(int i=0;i<=(int)S;i++){
//		cout<<dp[i]<<endl;
		if(dp[i]==1)
			res=min(res, S-i);//find the maximum i which is the best sum of one subset
	}
	//S1 = i; S2 = 2*S -S1 = 2*S - i
	//ABS(S1-S2) = 2*ABS(S-i)
	return 2*res;

}

int main(){
	vector<int> data(10,0);
	data[0] = 1;
	data[1] = 1;
	data[2] = 1;
	data[3] = 2;
	data[4] = 2;
	data[5] = 2;
	data[6] = 3;
	data[7] = 3;
	data[8] = 3;
	data[9] = 3;

	cout<<BP(data)<<endl;
	return 0;
}
