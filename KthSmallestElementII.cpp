/*find the kth smallest number from two sorted arrays
 *e.g
 *input 1 3 5 7 9,  2 4 6 8 10, k =7
 *output 7
 */
#include<iostream>
#include<limits.h>
using namespace std;


int kthsmallest(int* a,int lena, int* b, int lenb, int k){	
	//if only one array left, return corresponding value directly
	if(lena==0)
		return b[k-1];
	if(lenb==0)
		return a[k-1];
	//initialize i according to the length relationship
	int i=(int)((double)lena/(lena+lenb)*(k-1));
	//make sure i+j-1=k
	int j=k-1-i;
	cout<<"i:"<<i<<";j:"<<j<<"k:"<<k<<endl;
	
	//initialize A[i-1] A[i] B[j-1] B[j]
	int Ai_1 = (i==0)?INT_MIN:a[i-1];
	int Bj_1 = (j==0)?INT_MIN:b[j-1];
	int Ai = (i==lena)?INT_MAX:a[i];
	int Bj = (j==lenb)?INT_MAX:b[j];

	//if can be selected, the one must be the smaller one between A[i] and B[i] 
	if(Bj_1<Ai && Ai<Bj)//if B[j-1]<A[i] and A[i]<B[j], then A[i] since A[i]>A[i-1] and A[i] is the smallest one which is bigger than all the previous k-1 values
		return Ai;
	else if(Ai_1<Bj && Bj<Ai)//if [Ai-1]<B[j] and B[j]<A[i], then B[j] since B[j]>B[j-1] and B[j] is the smallest one which is bigger than all the previous k-1 values
		return Bj;

	//if cannot be selected
	//if A[i]<B[j], values before A[i] and after B[j] can be cleared, update k
	if(Ai<Bj)
		return kthsmallest(a+i+1,lena-i-1,b,j,k-i-1);
	//if B[j]>A[i], values before B[j] and after A[i] can be cleared, update k
	else
		return kthsmallest(a,i,b+j+1,lenb-j-1,k-j-1);
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
