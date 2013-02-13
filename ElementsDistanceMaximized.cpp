/*
  Given an array A of integers, find the maximum of j-i subjected to the constraint of A[i] < A[j].
 */

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct tw{
	int val;
	int index;
};

int main(){
	int n;
	vector<int> arr;
	vector<tw> l;
	vector<tw> r;
	tw lc;
	tw rc;
	cout<<"Size of array:";
	cin>>n;
	for(int i=0; i<n;i++){
		int tmp;
		cout<<"Please input number "<<i<<":";
		cin>>tmp;	
		arr.push_back(tmp);
	}


	//store all the elements those are smaller than arr[0] and decreasing;
	lc.index=0;
	lc.val=arr[0];
	l.push_back(lc);
	for(int i=1;i<n;i++){
		if(arr[i]<lc.val){
			lc.index=i;
			lc.val=arr[i];
			l.push_back(lc);
		}
	}

	//store all the elements those are bigger than arr[n-1] and increasing
	rc.index=n-1;
	rc.val=arr[n-1];
	r.push_back(rc);
	for(int i=n-2;i>=0;i--){
		if(arr[i]>rc.val){
			rc.index=i;
			rc.val=arr[i];
			r.push_back(rc);
		}
	}

	int i_l=0;
	int i_r=r.size()-1;
	int maxlen=0;
	//compare the smallest left with biggest right	
	while(i_l<l.size()&&i_r>=0){
		while(l[i_l].val<r[i_r].val&&i_l<l.size()&&i_r>=0){
			maxlen=max(maxlen,r[i_r].index-l[i_l].index);
			i_r--;
		}
		i_l++;
	}

	cout<<"Max(j-i) where A[j]>A[i]:"<<maxlen<<endl;

	return 0;
}

