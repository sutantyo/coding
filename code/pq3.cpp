#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<char,int>> data;

int main(int argc, char* argv[]){

	//priority_queue< pair<int,pair<char,int>> > pq;
	//priority_queue< pair<int,pair<char,int>>, vector<pair<int,pair<char,int>>>, greater<pair<int,pair<char,int>>> > pq;
	priority_queue<data,vector<data>,greater<data>> pq;
	pq.push(make_pair(3,make_pair('a',4)));
	pq.push(make_pair(5,make_pair('a',2)));
	pq.push(make_pair(3,make_pair('c',1)));
	pq.push(make_pair(5,make_pair('b',3)));
	pq.push(make_pair(5,make_pair('b',3)));
	pq.push(make_pair(5,make_pair('b',4)));

	while(!pq.empty()){
		cout << pq.top().first << " " << pq.top().second.first << " ";
		cout << pq.top().second.second << endl;
		pq.pop();
	} 

	cout << endl << "NEXT" << endl;

	auto comp = [&](vector<int>* a, vector<int>* b){
		return *a > *b;
	};
	priority_queue<vector<int>*,vector<vector<int>*>,decltype(comp) > pq2(comp);
	pq2.push(new vector<int>({1,2,3}));
	pq2.push(new vector<int>({1,2,3,4}));
	pq2.push(new vector<int>({1,2}));
	pq2.push(new vector<int>({7,2,3}));
	pq2.push(new vector<int>({7,7,3}));
	pq2.push(new vector<int>({6,2,3}));
	pq2.push(new vector<int>({4,2,3}));

	while(!pq2.empty()){
		vector<int>* cur = pq2.top();
		for(auto& x : *cur)
			cout << x << " ";
		cout << endl;
		pq2.pop();
	}

	vector<int> aaa = {1,2,3,4};
	vector<int> bbb = {2,3,4};
	cout << (aaa == bbb) << endl;
	cout << (aaa < bbb) << endl;
	cout << (aaa > bbb) << endl;

	sort(aaa.begin(),aaa.end(),greater<int>());
	for(auto& x : aaa)
		cout << x << " ";
	cout << endl;


}
