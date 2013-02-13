/*There is a keyboard pad with width x. At the beginning, the pos is at the
 * first row and first col.
 * Given a string "adhkjashfkuhqiuwq";
 * Find the path from the beginning, l->left, r->right, u->up, d->down
 * When Find each letter, enter "OK";
 * e.g.
 * input:
 * str = "abcdef", width= 3;
 * output:
 * OK r OK r OK dll OK r OK r Ok
 *
 *
 */

#include<iostream>
using namespace std;


string strpadpath(string word , int width){
	int N = word.length();
	char prechar ='a';
	string res;
	for(int i=0;i<N;i++){
		int totalcount = prechar - 'a';
		int prerow = totalcount/width;
		int precol = totalcount%width;

		int totalcurcnt = word[i] - 'a';
		int currow = totalcurcnt/width;
		int curcol = totalcurcnt % width;

		if(currow - prerow>0){
			int i=0;
			while(i<currow-prerow){
				res+="d";
				i++;
			}
		}
		if(currow - prerow<0){
			int i=0;
			while(i<prerow-currow){
				res+="u";
				i++;
			}
		}

		if(curcol - precol>0){
			int i=0;
			while(i<curcol-precol){
				res+="r";
				i++;
			}
		}
		if(curcol - precol<0){
			int i=0;
			while(i<precol-curcol){
				res+="l";
				i++;
			}
		}

		res +="OK";
		prechar = word[i];
	}
	return res;
}


int main(){
	string str;
	int width;
	cout<<"Input the string:"<<endl;
	cin>>str;
	cout<<"Input the width of the pad:"<<endl;
	cin>>width;
	cout<<strpadpath(str, width)<<endl;;
	return 0;
}
