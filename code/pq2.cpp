#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	priority_queue<pair<int,pair<string,int>>> pq;

	pq.push(make_pair(2,make_pair("a",6)));
	pq.push(make_pair(2,make_pair("b",3)));
	pq.push(make_pair(4,make_pair("a",3)));
	pq.push(make_pair(2,make_pair("a",7)));
	pq.push(make_pair(5,make_pair("a",3)));

	while(!pq.empty()){
		cout << pq.top().first << " " << pq.top().second.first;
		cout << " " << pq.top().second.second << endl;
		pq.pop();
	}

}
