#include <iostream>
#include "skiplist.cc"
using namespace std;
int main(){
	SkipList sl;
	sl.put(100,1);
	sl.put(99,2);
	cout<<sl.len()<<endl;
	int *val1, *val2;
	cout<<sl.get(10,val1)<<" "<<*val1<<endl;
	cout<<sl.get(99,val2)<<" "<<endl;
	return 0;
}
