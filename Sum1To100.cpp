//calculate sum of 1 to n without using judge, loop and compare

#include<iostream>
using namespace std;

class sum1ton{
	public:
		static int sum;
		static int count;

		sum1ton(){
			sum+=count;
			count++;
		}
};

int sum1ton::sum = 0;
int sum1ton::count = 1;

int main(){
	sum1ton test[100];
	cout<<test[0].sum<<endl;
	return 0;
}
