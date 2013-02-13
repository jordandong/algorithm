/*find the kth smallest number from two sorted arrays
 *e.g
 *input 1 3 5 7 9,  2 4 6 8 10, k =7
 *output 7
 */


#include<iostream>
using namespace std;


int kthsmallest(int* a,int lena, int* b, int lenb, int k){
	//only one array left, return corresponding value directly
	if(lena==0)
		return b[k-1];
	if(lenb==0)
		return a[k-1];

	//half the length
	int ma=lena/2;
	int mb=lenb/2;
	cout<<"ma:"<<ma<<";mb:"<<mb<<endl;
	//if sum of the two halves size is smaller than k, clear some elements and update k
	if(ma+mb+2<=k){
		if(a[ma]>b[mb])//if mid of A is bigger, the first half of B can be clear
			return kthsmallest(a,lena,b+mb+1,lenb-mb-1,k-mb-1);
		else//if mid of B is bigger, the first halt of A can be clear
			return kthsmallest(a+ma+1,lena-ma-1,b,lenb,k-ma-1);
	}
	else{//if sum of the two halves sizes is bigger than k, clear some elements and update k 	
		if(a[ma]>b[mb])//if mid of A is bigger than B, the second half of A can be clear
			return kthsmallest(a,ma,b,lenb,k);
		else//if the mid of B is bigger than A, the second half of B can be clear
			return kthsmallest(a,lena,b,mb,k);
	}
}


int main(){
	int sa,sb,k;
	cout<<"Size of a:";
	cin>>sa;
	int *a = new int[sa];
	for(int i=0;i<sa;i++)
		cin>>a[i];

	cout<<"Size of b:";
	cin>>sb;
	int *b = new int[sb];
	for(int i=0;i<sb;i++)
		cin>>b[i];

	cout<<"select Kth smallest:";
	cin>>k;

	int res = kthsmallest(a,sa,b,sb,k);
	cout<<"The "<<k<<"th smallest number is :"<<res<<endl;
	
	return 0;
}
