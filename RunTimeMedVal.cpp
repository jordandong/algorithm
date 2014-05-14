/*
 * Given that integers are read from a data stream. Find median of elements read so for in efficient way.
 *
 */

#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

struct mi_heap{
		bool operator() (const int &a, const int &b) const{
			return a>b;
		}
};

struct ma_heap{
		bool operator() (const int &a, const int &b) const{
			return a<b;
		}
};

int RunTimeMedVal(){
	priority_queue<int, vector<int>, ma_heap > max_heap;
	priority_queue<int, vector<int>, mi_heap > min_heap;
	while(1){
		int a;
		string s;
		stringstream ss;
		cout<<"input next num:";
		cin>>s;
		ss<<s;
		if(ss.peek()<'0' || ss.peek()>'9')
			return 0;
		ss>>a;

		if(max_heap.empty()){
			max_heap.push(a);
			cout<<"max med is "<<max_heap.top()<<endl;
			continue;
		}

		if(min_heap.empty()){
			if(a<max_heap.top()){
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(a);
			}else{
				min_heap.push(a);
			}
			cout<<"both med is "<<((max_heap.top()+min_heap.top())/2.0)<<endl;
			continue;
		}
		
		int ma_top = max_heap.top();
		int mi_top = min_heap.top();

		if(max_heap.size() == min_heap.size()){
			if(a>mi_top)
				min_heap.push(a);
			else
				max_heap.push(a);

		}else if(max_heap.size()>min_heap.size()){
			if(a<ma_top){
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(a);
			} else{
				min_heap.push(a);
			}
		}else{
			if(a>mi_top){
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(a);
			}else{
				max_heap.push(a);
			}
		}

		if(max_heap.size()>min_heap.size()){
			cout<<"max med is "<<max_heap.top()<<endl;
		}else if(max_heap.size()<min_heap.size()){
			cout<<"min med is "<<min_heap.top()<<endl;
		}else{
			cout<<"both med is "<<((max_heap.top()+min_heap.top())/2.0)<<endl;
		}
		
	}
}

int main(){

	return RunTimeMedVal();

}
