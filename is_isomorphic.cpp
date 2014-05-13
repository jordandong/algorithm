/*
 *Given two (dictionary) words as Strings, determine if they are isomorphic. Two words are called isomorphic 
 *if the letters in one word can be remapped to get the second word. Remapping a letter means replacing all 
 *occurrences of it with another letter while the ordering of the letters remains unchanged. No two letters 
 *may map to the same letter, but a letter may map to itself. 
 *
 *Example: 
 *given "foo", "app"; returns true 
 *we can map 'f' -> 'a' and 'o' -> 'p' 
 *given "bar", "foo"; returns false 
 *we can't map both 'a' and 'r' to 'o' 
 *
 *given "turtle", "tletur"; returns true 
 *we can map 't' -> 't', 'u' -> 'l', 'r' -> 'e', 'l' -> 'u', 'e' -'r' 
 *
 *given "ab", "ca"; returns true 
 *we can map 'a' -> 'c', 'b'
 *
 *method 2:
 *aa ab  ---> true or false????
 *foo, bar ---> true or false???
 *abc, xca ---> true or false???
 */

#include<iostream>
#include<string>
using namespace std;

bool isomorphic(string s1, string s2){
	int size1 = s1.length();
	int size2 = s2.length();
	if(size1!=size2)
		return false;

	unsigned int mp1[256];
	unsigned int mp2[256];
	memset(mp1, 0, sizeof(mp1));
	memset(mp2, 0, sizeof(mp2));
	for(int i=0; i<size1; i++){
		if(s1[i] == s2[i])
			continue;
		if(mp1[s1[i]]==0)
			mp1[s1[i]] = s2[i];
		if(mp2[s2[i]]==0)
			mp2[s2[i]] = s1[i];

		if(mp1[s1[i]] != s2[i] || mp2[s2[i]] != s1[i])
			return false;
	}
	return true;
}

bool isomorphic2(string s1, string s2){
	int size1 = s1.length();
	int size2 = s2.length();
	if(size1!=size2)
		return false;

	unsigned int mp2[256];
	memset(mp2, 0, sizeof(mp2));
	for(int i=0; i<size1; i++){
		if(s1[i] == s2[i])
			continue;
		if(mp2[s2[i]]==0)
			mp2[s2[i]] = s1[i];
		else if (mp2[s2[i]] != s1[i])
			return false;
	}
	return true;
}

int main(){
	string s1, s2;
	cout<<"input string 1:";
	cin>>s1;
	cout<<"input string 2:";
	cin>>s2;
	cout<<"isomorphic is "<<isomorphic(s1, s2)<<endl;
	cout<<"isomorphic2 is "<<isomorphic2(s1, s2)<<endl;
}
