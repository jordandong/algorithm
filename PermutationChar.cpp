/*find all the permutations from a given string
 *e.g
 *input abc
 *output abc acb bac bca cba cab
 */

#include<iostream>
using namespace std;

int counter = 0;
//swap
void swap(char&a, char&b){
	char t;
	t = a;
	a = b;
	b = t;
}

void Permutation(char* pStr, char* pBegin){
	//if this is the last recurstion, return result
	if(*pBegin == '\0'){
		while(*pStr!='\0'){
			cout<<*pStr;
			pStr++;
		}
		cout<<endl;
		counter++;
	}
	//recursion
	else{
		for(char* pCh = pBegin; *pCh != '\0'; pCh++)
		{
			swap(*pBegin,*pCh);//swap the 1st with all the others after
			Permutation(pStr, pBegin+1);//call the recursion of the left n-1
			swap(*pBegin,*pCh);//swap back
		}
	}
}

int main(void)
{
	char str[] = "abcd";
	Permutation(str,str);
	cout<<counter<<endl;
	return 0;
}
