/*
 * Given a number, print all the unique combination of factors
 *
 *e.g.
 *Input a number: (q to quit):1
 *1 * 1
 *Input a number: (q to quit):2
 *1 * 2
 *Input a number: (q to quit):3
 *1 * 3
 *Input a number: (q to quit):4
 *1 * 4
 *2 * 2
 *Input a number: (q to quit):5
 *1 * 5
 *Input a number: (q to quit):6
 *1 * 6
 *2 * 3
 *Input a number: (q to quit):7
 *1 * 7
 *Input a number: (q to quit):8
 *1 * 8
 *2 * 4
 *2 * 2 * 2
 *Input a number: (q to quit):9
 *1 * 9
 *3 * 3
 *Input a number: (q to quit):10
 *1 * 10
 *2 * 5
 *Input a number: (q to quit):11
 *1 * 11
 *Input a number: (q to quit):12
 *1 * 12
 *2 * 6
 *2 * 2 * 3
 *3 * 4
 *Input a number: (q to quit):13
 *1 * 13
 *Input a number: (q to quit):14
 *1 * 14
 *2 * 7
 *Input a number: (q to quit):15
 *1 * 15
 *3 * 5
 *Input a number: (q to quit):16
 *1 * 16
 *2 * 8
 *2 * 2 * 4
 *2 * 2 * 2 * 2
 *4 * 4
 *Input a number: (q to quit):17
 *1 * 17
 *Input a number: (q to quit):18
 *1 * 18
 *2 * 9
 *2 * 3 * 3
 *3 * 6
 *Input a number: (q to quit):19
 *1 * 19
 *Input a number: (q to quit):20
 *1 * 20
 *2 * 10
 *2 * 2 * 5
 *4 * 5
  */

#include<iostream>
#include<vector>
using namespace std;

void PComb(int val, int s, vector<int> &res){
    if(val == 1){
        int n = res.size();   
        if(n == 0){
            cout<<val<<"*1"<<endl;;
            return;
        }
        if(n == 1){
            cout<<res[0]<<"*1"<<endl;;
            return;
        }
        for(int i = 0; i < n; i++){
            if(i==0)
                cout<<res[i];
            else
                cout<<"*"<<res[i];
        }
        cout<<endl;
        return;
    }

    for(int d = s; d > 1; d--){
        if(val%d == 0){
            res.push_back(d);
            PComb(val/d, d, res);
            res.pop_back();
        }
    }
}

int main(){
    for(int v = 30; v>=1; v-=1){
        vector<int> res;
        cout<<v<<"="<<endl;
        PComb(v, v, res);
        cout<<endl;
    }
    return 0;
}



#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
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
	for(unsigned int i =3; i*i<=num; i+=2){
		if(num%i == 0){
			return false;
		}
	}
	return true;
}

string num2str(unsigned int num){
	string s;
	unsigned int val = num%10;
	unsigned int next = num/10;
	if(next!=0){
		s = num2str(next);
	}
	s.push_back('0'+val);
	return s;
}

void unique_comb_factor(unsigned int num, unsigned int last_fac, string cur_str, vector<string> &res){
	if(last_fac == 1){
		res.push_back("1 * " +num2str(num));
		last_fac++;
	}
	
	for(unsigned int i=last_fac; i*i<=num; i++){
		unsigned div = num%i;
		if(div == 0){
			string tmp;
			unsigned int fac = num/i;
			tmp = cur_str + num2str(i) + " * ";
			res.push_back(tmp + num2str(fac));
			if(!isPrime(fac)){
				unique_comb_factor(fac, i, tmp, res);
			}
		}
	}
}

int main(){

	cout<<(num2str(290))<<endl;
	while(1){
		vector<string> vs;
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
			unique_comb_factor(num, 1, "", vs);
		}
		for(int i=0; i<vs.size(); i++){
			cout<<vs[i]<<endl;
		}
	}
	return 0;
}
