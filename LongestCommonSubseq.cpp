/*find the longest common substring
 *e.g.
 *input abcxyzdefg  xyzabcdefg
 *output abcdefg
 *
*/

#include<iostream>
#include<string>
using namespace std;
string LCS(string &s1,string &s2){
	int ls1 = s1.length();
	int ls2 = s2.length();
	//if one of them are null, then no results
	if(ls1==0||ls2==0)
		return "";
	//m*n dp table
	int c[ls1][ls2];
	string res;
	cout<<"s1 is "<<ls1<<", s2 is "<<ls2<<endl;
	
	int max=0,i=0,j=0;
	for(i=0;i<=ls1-1;i++){//from beginning
		for(j=0;j<=ls2-1;j++){//from beginnig
			if(s1.at(i)==s2.at(j)){
				if(i==0||j==0)
					c[i][j]=1;//edge pos set to 1 if equal
				else
					c[i][j]=c[i-1][j-1]+1;//add this new one to the previous results using two previous chars
			}
			else{
				if(i==0&&j==0)
					c[i][j]=0;//initial pos
				else if(i==0&&j!=0)
					c[i][j] = c[i][j-1];//edge pos, the same as previous pos
				else if(i!=0&&j==0)
					c[i][j] = c[i-1][j];//edge pos, the same as previous pos
				else
					//record the max one from previous two situations(left and up)
					c[i][j]=c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
			}
			//find the max
			if(c[i][j]>max){
				max=c[i][j];
			}
		}
	}
	if(max==0)
		return "";
	//output
	for(int i =0; i<ls1;i++){
		for(int j=0; j<ls2;j++){
			cout<<c[i][j]<<" ";
			//find the first commom element
			if(i==0&&j==0&&c[i][j]==1)
				res+=s2.at(j);
			else if(i==0&&j!=0&&c[i][j]==1&&c[i][j-1]==0)
				res+=s2.at(j);
			else if(i!=0&&j==0&&c[i][j]==1&&c[i-1][j]==0)
				res+=s2.at(j);
			//find all the other commom elements in the pos happened the first time
			else if((c[i][j]==(c[i-1][j]+1))&&(c[i][j]==(c[i][j-1]+1)))
				res+=s2.at(j);
		}	
		cout<<endl;
	}

	return res;
}

int main(){
	string a;
	string b;
	cin>>a>>b;
	cout<<LCS(a,b)<<endl;
	return 0;
}
