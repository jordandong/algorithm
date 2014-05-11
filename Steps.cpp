/*find how many ways to finish the n steps by 1 2 3 paces
 *e.g
 *input 4
 *output 7 (1111,112,121,211,22,13,31)
 *O(lgn) alg added, actually nth Fibonacci num is the step(n-1) when steps are one or two.
 *e.g n =5
 *1 1     1 1 1
 *2       2 1     ----> 2*3 =  6
 *        1 2
 *                               -------> 6 + 2 == 8
 *1   2   1 1
 *        2       -----> 1*2 = 2 
 *binary search, half*half + (half-1)*(half-1) which is connection with 2   
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;


string convertInt(int number)
{
	if (number == 0)
		return "0";
	string temp="";
	string returnvalue="";
	while (number>0)
	{
		temp+=number%10+48;
		number/=10;
	}
	for (int i=0;i<temp.length();i++)
		returnvalue+=temp[temp.length()-i-1];
	return returnvalue;
}


int steps(int n,int *step, string s, vector<string>* v){
	//n<0 impossible step
	if (n<0)
		return 0;
	//n==0 finish walking
	if (n==0){
		v->push_back(s);
		return 1;
	}

	if(step[n]>0){
		v->push_back(s+" at n = "+convertInt(n));
		return step[n];
	}
	//walk in three ways for first pace, and recursion for next n-i steps
	int a = steps(n-1, step, s+"1", v);
	int b = steps(n-2, step, s+"2", v);
	int c = steps(n-3, step, s+"3", v);
	step[n] = a + b + c;
	
	return step[n];
}

int stepsDP(int n){
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n;i++){
		if(i>=3)
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		else
			dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int twostepsDP(int n){
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int steps_lgn(int n){

	if(n==0 || n==1)
		return 1;
	if(n==2)
		return 2;
	int first_half = n&1?(n-1)>>1:n>>1;
	int second_half = n&1?(n+1)>>1:n>>1;
	return steps_lgn(first_half)*steps_lgn(second_half) + steps_lgn(first_half-1)*steps_lgn(second_half-1);
}

int main(){
	int n;
	vector<string> vec;
	cout<<"Please input the number of steps: "<<endl;
	cin>>n;
	int* step = new int[n+1];
	int res=steps(n, step,"!", &vec);
	int dp = stepsDP(n);

	cout<<"There are "<<res<<" /"<<dp<<" ways to finish theses steps!!"<<endl;

	cout<<"lgn -> There are "<<steps_lgn(n)<<" / "<<twostepsDP(n)<<" ways to finish these steps!!"<<endl;

	for (int i=0;i<vec.size(); i++)
		cout<<i<<":" <<vec.at(i)<<endl;
	return 0;
}
