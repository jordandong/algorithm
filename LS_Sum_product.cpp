/* find the largest subseq with max sum
 *
 * find the largest sunseq with max product
 */
#include<iostream>
#include<vector>
using namespace std;

double LS_SUM(vector<double> &data){
	int size = data.size();
	if(size == 0)
		return 0;
	vector<double> dp(size, 0);
	dp[0] = data[0];
	double res = data[0];
	for(int i = 1; i<size; i++){
		dp[i] = data[i];
		for(int j = i-1; j>=0; j--){
			dp[i] = max(dp[i], dp[j] + data[i]);
		}
		res = max(res, dp[i]);

	}
	return res;
}

double LS_PRODUCT(vector<double> &data){
	int size = data.size();
	if(size == 0)
		return 0;
	vector<double> dp_neg(size, 1);
	vector<double> dp_pos(size, -1);
	dp_neg[0] = data[0]<0?data[0]:1;
	dp_pos[0] = data[0]>=0?data[0]:-1;
	double res = data[0];
	for(int i = 1; i<size; i++){
	        dp_neg[i] = data[i]<0?data[i]:1;
	        dp_pos[i] = data[i]>=0?data[i]:-1;
		for(int j = i-1; j>=0; j--){
			if(data[i]>=0){
				dp_neg[i] = min(dp_neg[i], dp_neg[j] * data[i]);
				dp_pos[i] = max(dp_pos[i], dp_pos[j] * data[i]);
			}else{
				dp_pos[i] = max(dp_pos[i], dp_neg[j] * data[i]);
				dp_neg[i] = min(dp_neg[i], dp_pos[j] * data[i]);
			}
		}
		res = max(res, dp_pos[i]);

	}
	return res;
}

int main(){

        vector<double> data;
	for(int i=0; i<10; i++){
		double a;
		cout<<"Input "<<i+1<<"th elem:"<<endl;
		cin>>a;
		data.push_back(a);
	}
	cout<<"LS_SUM is "<<LS_SUM(data)<<endl;
	cout<<"LS_PRODUCT is "<<LS_PRODUCT(data)<<endl;

	return 0;
}
