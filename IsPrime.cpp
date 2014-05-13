/*
 * Given a number, and return if it is a prime or not
 */


#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

bool isPrime(unsigned int num){

	if(num < 2){
		return false;
	}
	if(num == 2){
		return true;
	}
	if((num&1) == 0){
		return false;
	}
	for(long i =3; i*i<=(long)num; i+=2){
		if(num%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int a = 9;
	while(1){
		stringstream ss;
		string s;
		cout<<"Input a number: (q to quit):";
		cin>>s;
		ss<<s;	
		unsigned int num=0;
		if(ss.peek()<'0' || ss.peek()>'9')
			return 1;
		else{
			ss>>num;
			cout<<(isPrime(num)?"Prime":"Not Prime")<<endl;
		}
	}
	return 0;
}
