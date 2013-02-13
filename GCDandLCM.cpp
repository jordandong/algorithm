/* Given two integer a and b
 * ouput the GCD and LCM
 * e.g.
 * input:	12 24, 6 15, 24 36 
 * output:	12 14, 3 30, 12 72
 *
 */

#include<iostream>
using namespace std;

int GCD(int a, int b){
	int m=max(a,b);
	int n=min(a,b);
	if(n==0)
		return m;
	return (GCD(n,m%n));
}

int LCM(int a, int b){
	int gcd = GCD(a,b);
	return a*b/gcd;
}

int main(){
	int a;
	int b;
	cout<<"Input 2 integers those are bigger than 0:"<<endl;
	cin>>a;
	cin>>b;
	cout<<"The GCD is "<<GCD(a,b)<<endl;
	cout<<"The LCM is "<<LCM(a,b)<<endl;
	return 0;
}
