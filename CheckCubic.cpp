/*
 *A function to judge whether a number is a power of 3
 */

#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

bool pow3(int num){
    num=abs(num);
    if(num==0)
		return false;
    if(num==1)
		return true;
    while(num==sqrt(num)*sqrt(num))
		num=sqrt(num);

    return (num%3==0)?pow3(num/3):false;
}

int main(int argc, char *argv[]){
	char* str = argv[1];
	int num = 0;
	while(*str!='\0'){
		num*=10;
		num+=*str-'0';
		str++;
	}
	if(pow3(num))
		cout<<"YES,"<<num<<" is a number of power 3!!"<<endl;
	else
		cout<<"No,"<<num<<" is not a number of power 3!!"<<endl;
	return 0;
}
