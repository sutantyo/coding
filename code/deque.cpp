#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	deque<int> q = {1,2,3,4,5};

	cout << q.back() << endl;
	cout << q.front() << endl;


	q.insert(q.begin()+3,3,6);


	for(auto& x : q)
		cout << x << " ";
	cout << endl;



}
