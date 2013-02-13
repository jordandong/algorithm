//��һ��int���͵Ĳ��ظ������飬����һ��target number��������������ȡ��������ӣ�Ҫ����ж����ַ������Եõ����target����������{1��2}��target��5��������1+1+1+1+1��Ҳ������1+2+2�ȵ�

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
