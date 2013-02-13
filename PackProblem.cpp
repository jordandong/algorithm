/*
 *	01 Given a pack with volume V and items with volume v and price c
 *	every itme can be placed once
 *	02 items can be placed more than once
 *	Goal:
 *	make the pack contains the items with highest total price
 */
#include <iostream>
#include <vector>
using namespace std;

int OnePack01(vector<pair<int, int> > item, int V){
	int size = item.size();
	vector<int> dp(V+1, 0);
	for(int i=0; i<size;i++){
		for(int vol=V; vol>=item[i].first;vol--){
			dp[vol] = max(dp[vol], dp[vol-item[i].first]+item[i].second); 
		}
	}
	return dp[V];
}

int OnePack02(vector<pair<int, int> > item, int V){
	int size = item.size();
	vector<int> dp(V+1, 0);
	for(int i=0; i<size;i++){
		for(int vol=item[i].first;vol<=V;vol++){
			dp[vol] = max(dp[vol], dp[vol-item[i].first]+item[i].second); 
		}
	}
	return dp[V];
}



struct gift{
	int vol;
	int price;
	int num;
};

int OnePack03(vector<struct gift> item, int V){
	int size = item.size();
	vector<int> dp(V+1, 0);
	for(int i=0; i<size;i++){
		if(item[i].vol*item[i].num>=V)//02 pack
			for(int vol=item[i].vol;vol<=V;vol++){
				dp[vol] = max(dp[vol], dp[vol-item[i].vol]+item[i].price); 
			}
		else{//01 pack
			int k =1;
			int amount = item[i].num;//binary components
			while(k<item[i].num){
				for(int vol=V; vol>=k*item[i].vol;vol--){
					dp[vol] = max(dp[vol], dp[vol-k*item[i].vol]+k*item[i].price); 
				}
				amount-=k;
				k<<=1;
			}
			for(int vol=V; vol>=amount*item[i].vol;vol--){
				dp[vol] = max(dp[vol], dp[vol-amount*item[i].vol]+amount*item[i].price); 
			}
		}
	}
	return dp[V];
}

int main(){
	vector<pair<int, int> > data;
	data.push_back(make_pair(1,1));
	data.push_back(make_pair(2,2));
	data.push_back(make_pair(3,4));
	data.push_back(make_pair(4,6));
	data.push_back(make_pair(5,1));
	data.push_back(make_pair(6,2));
	data.push_back(make_pair(7,5));
	data.push_back(make_pair(8,6));
	data.push_back(make_pair(9,1));
	data.push_back(make_pair(10,2));
	data.push_back(make_pair(11,3));

	cout<<OnePack01(data, 10)<<endl;

	cout<<OnePack02(data, 10)<<endl;
	return 0;
}
