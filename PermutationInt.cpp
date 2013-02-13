/*find all the permutations from a given array
 *e.g
 *input abc
 *output abc acb bac bca cba cab
 */
#include<iostream>
using namespace std;

int counter=0;
//swap
void Swap(char& a, char& b){
	char temp = a; 
	a = b; 
	b = temp; 
}

void Perm(char list[], int k, int m) {
	int i; 
	//if the last recursion, return results
	if (k == m) {
		for (i = 0; i <= m; i++) 
			cout<<list[i]; 
		cout<<endl;
		counter++;
	} 
	//recursion for every pos
	else{ 
		//from the first pos
		for (i=k; i <= m; i++) { 
			Swap (list[k], list[i]);// swap 1st with all the other elements after 
			Perm (list, k+1, m); //recursion the next n-1
			Swap (list [k], list [i]); //swap back
		}
	} 
}


int main(int argv, char* argc[]) { 
	char s[]="12345"; 
	Perm(s, 0, 4);
	cout<<"Total situations: "<<counter<<endl;
	return 0; 
}
