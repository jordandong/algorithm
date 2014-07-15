/* add two int withiout + - * and /
 * e.g.
 *    input 1 ,  2   -----> 3
 *    input 1 , -2   -----> -1
 *    input -2 , 1   -----> -1
 *    input -1 ,-2   -----> -3
 */

#include<iostream>
using namespace std;

void printBin(int a){
	for(int i = 31; i>=0; i--){
		if( (1<<i) & a)
			cout<<"1 ";
		else
			cout<<"0 ";
	}
	cout<<endl;
}

int add_without_asmd(int a, int b){
	int x, y;
	do{
	    cout<<"a: ";		
            printBin(a);
	    cout<<"b: ";		
            printBin(b);

	    x = a & b;
	    y = a ^ b;
	    cout<<"x: ";		
            printBin(x);
	    cout<<"y: ";		
            printBin(y);
	    
	    a=x<<1;
	    b=y;
	}while(a);
	return y;
}

int main(){
	int a;
	int b;
	cin>>a>>b;
	cout<<add_without_asmd(a,b)<<endl;

}
