/* Given a array, find three index which meets i<j<k and A[i]<A[j]<A[k]
 */
#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int> > find3(int* A, int n){
	vector<pair<int,int> > ret = vector<pair<int, int> >(3, pair<int, int>(-1,-1));
	int count = 1;
	int min = 0;
	ret[0].first=0;
	ret[0].second=A[0];
	for(int i=1; i<n; i++){
		int x = A[i];
		if(x > A[ret[count-1].first]){
			ret[count].first=i;
			ret[count++].second=A[i];
			if(count == 3)
				break;
		}else{
			if(x <= A[min])
				min = i;
			else{
				ret[0].first = min;
				ret[0].second = A[min];
				ret[1].first = i;
				ret[1].second = A[i];
				count = 2;
			}
		}
	}	
	if(count == 3)
		return ret;
	else
		return vector<pair<int,int> >(3, pair<int, int>(-1,-1));
}


vector<pair<int, int> > find3II(int* A, int n){
	vector<pair<int,int> > ret = vector<pair<int, int> >(3, pair<int, int>(-1,-1));
	int*dp =new int[n];
	dp[0]=0;
	dp[n-1]=n-1;
	//dp数组里保存到从最左边到当前i元素为止最小的数的index
	for(int i=1;i<n-1;i++)
		dp[i]=A[i]<A[dp[i-1]]?i:dp[i-1];
	for(int i=n-2;i>0;i--){
		// 如果当前元素x比最左边到当前元素最小元素大，且当前元素比最右边
		// 到当前元素最大元素小的话，则结果存在，输出
		if(A[i]>A[dp[i-1]] && A[i]<A[dp[i+1]]){
			ret[0].first = dp[i-1];
			ret[0].second = A[dp[i-1]];
			ret[1].first = i;
			ret[1].second = A[i];
			ret[2].first = dp[i+1];
			ret[2].second =A[dp[i+1]];
			return ret;
		}
		//dp数组i的右边此时动态更新从最右边往i元素看最大的数的index
		dp[i]=A[i]>A[dp[i+1]]?i:dp[i+1];
	}
	return vector<pair<int, int> >(3, pair<int, int>(-1,-1));
}

int main(){
	int A[5] = {-2,-101,-100,-102,-1};
	int B[5] = {5,4,3,2,1};
	vector<pair<int, int> > res = find3II(B, 5);
	for(int i=0;i<3;i++){
		cout<<"A["<<res[i].first<<"]="<<res[i].second<<endl;
	}
	return 0;
}
