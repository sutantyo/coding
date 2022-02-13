#include<bits/stdc++.h>
using namespace std;

class Test{

	public:
		priority_queue<int,vector<int>,greater<int>> pq;

		Test(){
		}

};

int main(){

	Test a;
	a.pq.push(50);
	a.pq.push(20);
	cout << a.pq.size() << endl;
	cout << a.pq.top() << endl;

	cout << min(0,a.pq.size())<< endl;
}
