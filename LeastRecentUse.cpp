/*	Implement a LRU algorithm, LRU - Least Recently Used
 *	List is implemented by double linked list. 
 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;
#define MAX_SIZE 10

class LRU{
	public:
		list<pair<string,int> > entrylist;
		unordered_map<string, list<pair<string,int> >::iterator> entrymap;
		int size;
	public:
		LRU(){
			size = 0;
		};
		void add(string, int);
		void del();
		int get(string);
};

void LRU::add(string key, int value){
	if(entrymap.find(key)==entrymap.end()){
		if(size==MAX_SIZE)
			del();
	}else{
		entrylist.erase(entrymap[key]);
		size--;
	}
	entrylist.push_front(make_pair(key, value));
	entrymap[key] = entrylist.begin();
	size++;
}


void LRU::del(){
	size--;
	list<pair<string, int> >::reverse_iterator it = entrylist.rbegin();
	entrymap.erase(it->first);
	entrylist.pop_back();
}

int LRU::get(string key){
	if(entrymap.find(key)!=entrymap.end()){
		int value = entrymap[key]->second;
		entrylist.erase(entrymap[key]);
		entrylist.push_front(make_pair(key, value));
		entrymap[key] = entrylist.begin();
		return value;
	} else
		return -1;
}

void test(LRU l){
	cout<<"entrylist size:"<<l.entrylist.size()<<endl;
	list<pair<string, int> >::iterator it1;
	for(it1=l.entrylist.begin();it1!=l.entrylist.end();it1++)
		cout<<it1->first<<":"<<it1->second<<endl;
	cout<<"entrymap size: "<<l.entrymap.size()<<endl;
	unordered_map<string, list<pair<string, int> >::iterator>::iterator it;
	for(it = l.entrymap.begin(); it != l.entrymap.end(); ++it)
		cout<<it->first<<endl;
}
int main(){
	LRU l;
	test(l);

	cout<<endl<<"add 10 items"<<endl;
	l.add("abc", 100);
	l.add("abc1", 101);
	l.add("abc2", 102);
	l.add("abc3", 103);
	l.add("abc4", 104);
	l.add("abc5", 105);
	l.add("abc6", 106);
	l.add("abc7", 107);
	l.add("abc8", 108);
	l.add("abc9", 109);
	test(l);

	cout<<endl<<"get sss: "<<l.get("sss")<<endl;
	test(l);

	cout<<endl<<"add aaa 20"<<endl;
	l.add("aaa", 20);
	test(l);
	
	cout<<endl<<"add abc 200"<<endl;;
	l.add("abc", 200);
	test(l);

	cout<<endl<<"get abc: "<<l.get("abc")<<endl;
	test(l);

	cout<<endl<<"add abc3 1000 "<<endl;;
	l.add("abc3", 1000);
	test(l);
	
	cout<<endl<<"get abc5: "<<l.get("abc5")<<endl;
	test(l);

	cout<<endl<<"del two items"<<endl;
	l.del();
	l.del();
	test(l);


	return 0;	
}
