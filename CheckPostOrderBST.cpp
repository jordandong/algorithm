/*
 *	Given a sequence of number, check if the sequence is a post order of BST
 *	e.g
 *	input:
 *		123456 -> yes
 *		837	->	no
 */

#include<iostream>
#include<math.h>
#include<limits.h>
#include<stack>
using namespace std;
//The last element must be the root
int scanPostOrder(int *A, int idx, int minVal, int maxVal){
  if (idx<0||A[idx]<minVal||A[idx]>maxVal)
	  return idx; //if not meet the condition, finishing scan,return to parent
  int val = A[idx];
  idx = scanPostOrder(A, idx-1, val, maxVal);  //right tree
  return scanPostOrder(A, idx, minVal, val);   //left tree
  //if idx<0, then all the nodes are assigned
}

bool checkPostOrder(int *A, int n){
  return scanPostOrder(A, n-1, INT_MIN, INT_MAX) < 0;
}


bool checkPostOrderII(int *A, int n){
	stack<int> s;
	int max=INT_MAX;
	for(int i=n-1; i>=0;i--){
		int x = A[i];
		if(x>max)
			return false;
		while(!s.empty() && x<s.top()){
			max=s.top();
			s.pop();
		}
		s.push(x);
	}
	return true;
}


int checkPostOrderIII(int nums[], int start, int end){
       int i,j;
       if (start>=end)
		   return 1;
       i = start;
       //left tree
	   while (i<end&& nums[i]<nums[end])
		   i++;
	   i--;	
	   //right tree
	   j = end-1;
	   while (j >= start && nums[j] > nums[end])
		   j--;
	   j++;
	   if(i+1< j){
		   return 0;
	   }else{
		   return checkPostOrderIII(nums,start,i)&&checkPostOrderIII(nums,j,end-1);
	   }
}

int main(){
	int A[5]={1,2,8,3,7};
	int B[5]={1,2,3,4,5};
	cout<<checkPostOrder(A,5)<<endl;
	cout<<checkPostOrderII(A,5)<<endl;
	cout<<checkPostOrderIII(A,0,4)<<endl;
	return 0;
}

