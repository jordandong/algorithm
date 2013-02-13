//给一个整数数组， 找到其中包含最多连续数的子集，比如给：15, 7, 12, 6, 14, 13, 9, 11
//则返回: 5:[11, 12, 13, 14, 15] 

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int,int> continuousSubset(vector<int> &data){
	int N = data.size();
	unordered_map<int, int> mp;
	int max_begin = -1;
	int max_count = 0;
	for(int i=0; i<N; i++)
		mp[data[i]] = 1;

	for(int i=0; i<N; i++){
		if(mp.find(data[i])!=mp.end()){
			int count = 1;
			int begin = data[i];
			mp.erase(data[i]);
			int key = data[i];
			while(mp.find(++key)!=mp.end()){
				count++;
				mp.erase(key);
			}

			key=data[i];
			while(mp.find(--key)!=mp.end()){
				count++;
				begin=key;
				mp.erase(key);
			}

			if(count>max_count){
				max_count=count;
				max_begin=begin; 
			}
		}
	}
	return make_pair(max_begin, max_count);

}

int main(){
	
	vector<int> data;
	int N =20;
	for(int i=0;i<N;i++)
		data.push_back(i);
	data[2]=0;
	data[7]=0;
	data[17]=0;

	for(int i=0;i<N;i++)
		cout<<data[i]<<" ";
	cout<<endl;

	pair<int, int> res=continuousSubset(data);
	cout<<res.first<<" "<<res.second<<endl;
	return 0;
}
