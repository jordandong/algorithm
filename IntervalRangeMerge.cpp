/*给定一个大整数N,比如N = 100, 有如下的初始有序序列位于[0, N - 1]之间
 * [0 1]   [4 5 6]   [9 10 11] [20] [50] [90] [95 96] [98 99]
 *
 * 设计一个数据结构保存这个初始序列，然后写一个函数，接受个input参数x, 满足
 * 0 <= x <= N - 1
 * 1) 假如x在该结构中不存在，出错处理
 * 2) 假如x在该结构中存在，返回x之后第一个不存在的数，并把该数写入结构中
 *
 * 例如
 * x = 8, 出错，初始序列中没有8
 * x = 5, 返回7， 序列变为
 * [0 1]   [4 5 6 7]   [9 10 11] [20] [50] [90] [95 96] [98 99]
 * x = 4, 返回8, 序列变为
 * [0 1]   [4 5 6 7 8]   [9 10 11] [20] [50] [90] [95 96] [98 99]
 * x = 0, 返回2, 序列变为
 * [0 1 2]   [4 5 6 7 8]   [9 10 11] [20] [50] [90] [95 96] [98 99]
 * x = 95, 返回97，序列变为
 * [0 1 2]   [4 5 6 7 8]   [9 10 11] [20] [50] [90] [95 96 97 98 99]
 * x = 94, 出错，找不到合适的数>>
 *
 */
#include <iostream>
#include <map>
using namespace std;

bool search(int x,  map<int,int> &data){
	map<int, int>::iterator it = data.find(x);
	if(it==data.end())
		return false;
	if((*it).second==0)
		return false;
	
	while(it->second!=0&&it!=data.end())
		it++;
	it--;
	data[1+it->first] = 1;
	return true;
}

void output_map(map<int, int> &data){
	map<int, int>::iterator it;
	it = data.begin();
	while(it!=data.end()){
		cout<<(*it).first<<" , "<<(*it).second<<endl;
		it++;
	}
	cout<<endl;
}

int main(){
	map<int, int> data;
	for (int i = 1; i<10; i++){
		data[i] = i%2;
	}
	
	output_map(data);
	search(1, data);
	output_map(data);
	search(2, data);
	output_map(data);
	search(5, data);
	output_map(data);
	search(9, data);
	output_map(data);

	return 0;
}
