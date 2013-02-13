/*find all the permutation without duplications
 *e.g
 *input abb
 *output abb bab bba
 */


#include<iostream>
using namespace std;
int counter = 0;


//if we have swap the same value before the current pos, then false to avoid duplication
bool IsSwap(char* pBegin , char* pEnd){
	char *p;
	for(p = pBegin ; p < pEnd ; p++){
		if(*p == *pEnd)
			return false;
	}
	return true;
}

void swap(char&a, char&b){
	char t =a;
	a = b;
	b = t;
}

void Permutation(char* pStr , char *pBegin){
	//when all the values are recursed from 1 to nth, give results
	if(*pBegin == '\0'){
		while(*pStr!='\0'){
			cout<<*pStr;
			pStr++;
		}
		cout<<endl;
		counter++;
	}
	else{
		for(char *pCh = pBegin; *pCh != '\0'; pCh++){
			//decide whether swap the value at beginning and the current pos
			if(IsSwap(pBegin , pCh)){
				//swap the first value with the 2 to nth value
				//then call recursion for minus 1 length
				swap(*pBegin , *pCh);
				Permutation(pStr , pBegin + 1);
				swap(*pBegin , *pCh);
			}
		}
	}
}

int main(void)
{
	char str[] = "abcb";
	Permutation(str , str);
	cout<<"Total situations: "<<counter<<endl;
}
