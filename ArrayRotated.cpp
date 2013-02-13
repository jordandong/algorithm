/*rotated swich the array from the nth element
 * and then find the minimum one
 * e.g
 * input	2222227	n=3
 * output	2272222	min = 2
 */

#include<iostream>
using namespace std;

int sw(int *arr, int n, int length){
	//store the first n-1 elements
	int* tmp = new int[n-1];
	for(int i=0;i<n-1;i++)
		tmp[i]=arr[i];
	//assign the first pos with the n pos and so on
	//assign the last n-1 pos from tmp array
	for(int j=0;j<length;j++){
		if(j+n-1<length)
			arr[j]=arr[j+n-1];
		else
			arr[j]=tmp[j-length+n-1];
	}
	return 0;	
}

int findmin(int* arr,int left, int right){
	
	//return the only element
	if (left==right)
		return arr[left];
	//mid value
	int mid = (left  + right)/2;
	//mid=left and mid = right, we know nothing, find all situations
	if(arr[mid]==arr[left]&&arr[mid]==arr[right]){
	
		int a = findmin(arr, left, mid);
		int b = findmin(arr, mid+1,right);
		return a<b?a:b;
	}
	//if left<right, left must be the min
	else if(arr[left]<arr[right])
		return arr[left];
	//if mid >= left and mid >=right, min must be in the right part
	else if(arr[mid]>=arr[left]&&arr[mid]>=arr[right])
		return	findmin(arr, mid+1,right);
	//if mid <= left and mid <= right, min must be in the left part
	else if(arr[mid]<=arr[left]&&arr[mid]<=arr[right])
		return findmin(arr, left,mid);
	else return arr[left];
}


int main(void){
	int s[7] = {0, 1, 3 ,3 ,3 ,3 , 7};
	int num;
	cin>>num;
	sw(s, num,sizeof(s)/sizeof(int));
	for(int j =0; j<sizeof(s)/sizeof(int);j++)
		cout<<s[j];
	cout<<endl;

	cout<<"MIN:"<<findmin(s,0,6)<<endl;

	return 0;
}


