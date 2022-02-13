#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	priority_queue<pair<int,pair<char,int>>> pq;


	pq.push({3,make_pair('c',1)});
// alternatively: pq.emplace(3,make_pair('c',1));
	pq.emplace(5,make_pair('a',2));
	pq.push(make_pair(3,make_pair('a',4)));
	pq.push(make_pair(5,make_pair('b',4)));
	pq.push(make_pair(5,make_pair('b',3)));
	pq.push(make_pair(5,make_pair('b',3)));

	while(!pq.empty()){
		cout << pq.top().first << " " << pq.top().second.first;
		cout << " " << pq.top().second.second << endl;
		pq.pop();
	}

}
