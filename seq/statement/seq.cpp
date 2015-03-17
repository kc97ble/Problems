#include <bits/stdc++.h>
using namespace std;

struct Group{
	int value;
	int length;
	int rank;
	Group *parent, *prev, *next;
	Group(int value){
		this->value = value;
		length = 1;
		parent = NULL;
		rank = 1;
		prev = next = NULL;
	}
	
	bool isRoot(){
		return parent==NULL;
	}
	
	Group* getRoot(){
		if (isRoot()) return this;
		return parent = parent->getRoot();
	}	
		
	int getValue(){
		return getRoot()->value;
	}
	
	int getLength(){
		return getRoot()->length;
	}
	
	Group* getPrev(){
		return getRoot()->prev;
	}
	
	Group* getNext(){
		return getRoot()->next;
	}
	
	void increase(int &left, int value){
		Group* root = getRoot();
		long long need = 1LL * root->length * (value - getValue());
		if (left >= need){
			left -= need;
			root->value = value;
		} else {
			root->value += left / getLength();
			left = 0;
		}		
	}
};

void join(Group* le, Group* ri){
	le = le->getRoot(); ri = ri->getRoot();
	if (le == ri) return;
	
	if (le->rank > ri->rank){
		ri->parent = le;
		le->next = ri->next;
		le->length += ri->length;
	} else {
		if (le->rank == ri->rank) ri->rank++;
		le->parent = ri;
		ri->prev = le->prev;
		ri->length += le->length;
	}
}

const int limit = 1000000 + 5;
list<Group*> event[limit];
Group* a[limit];

void push(Group* cur){
	if (cur->getValue() < cur->getPrev()->getValue() &&
		cur->getValue() < cur->getNext()->getValue() )
			event[cur->getLength()].push_back(cur);
}


void solve(){
	int n, k; scanf("%d%d",&n,&k);
	for(int i = 1; i < n; ++i) event[i].clear();
	for(int i = 0; i < n; ++i){
		int value; scanf("%d",&value);
		a[i] = new Group(value);
	}
	
	for(int i = 0; i < n; ++i){
		int j = (i+1) % n;
		a[i]->next = a[j];
		a[j]->prev = a[i];
	}
	
	for(int i = 0; i < n; ++i){
		int j = (i+1) % n;		
		if (a[i]->getValue() == a[j]->getValue()) join(a[i], a[j]);
	}
	
	for(int i = 0; i < n; ++i)
		if (a[i]->isRoot()) push(a[i]);
				
	for(int i = 1; i<n && k>0; ++i)
		while (!event[i].empty() && k){
			Group* cur = event[i].front(); event[i].pop_front();
			int prevValue = cur->getPrev()->getValue();
			int nextValue = cur->getNext()->getValue();
			int value = min(prevValue, nextValue);
					
			cur->increase(k, value);
			if (cur->getValue() == prevValue) 
				join(cur->getPrev(), cur);
			if (cur->getValue() == nextValue)
				join(cur, cur->getNext());
			push(cur);
		}
	
	long long result = 0;
	for(int i = 0; i < n; ++i){
		int j = (i+1) % n;		
		result += abs(a[i]->getValue() - a[j]->getValue());
	}
	cout << result << endl;
	for(int i = 0; i < n; ++i) delete a[i];	
}

int main(){
	//freopen("file.inp","r",stdin);
	solve();
}