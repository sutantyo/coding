#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	auto start = chrono::high_resolution_clock::now();
	
	priority_queue<vector<int>> pq;
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,3,8,9,10,11});
	pq.push({4,5,7,4,9,10,11});
	pq.push({4,5,7,8,6,10,11});
	pq.push({4,5,7,8,9,13,11});
	pq.push({4,5,7,8,9,10,21});
	pq.push({8,5,7,8,9,10,11});
	pq.push({4,9,7,8,9,10,11});
	pq.push({4,5,3,8,9,10,11});
	pq.push({4,5,7,2,9,10,11});
	pq.push({4,5,7,8,1,10,11});
	pq.push({4,5,7,8,9,14,11});
	pq.push({9,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,9,7,8,9,10,11});
	pq.push({4,8,9,8,9,10,11});
	pq.push({8,8,7,9,9,10,11});
	pq.push({8,8,7,9,9,10,11});
	pq.push({8,8,7,8,9,90,11});
	pq.push({8,8,7,8,9,90,11});
	pq.push({8,5,8,9,9,10,91});
	pq.push({8,5,8,8,9,10,11});
	pq.push({8,5,8,3,3,10,11});
	pq.push({8,5,8,8,3,10,11});
	pq.push({8,5,8,8,9,10,11});
	pq.push({8,5,7,8,9,30,11});
	pq.push({8,5,3,3,9,30,11});
	pq.push({8,3,3,3,8,10,11});
	pq.push({8,5,7,8,8,1011});
	pq.push({8,5,7,8,8,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({8,5,7,8,9,1011});
	pq.push({4,5,7,89,10,11});
	pq.push({4,5,79,10,11});
	pq.push({4,57,89,10,11});
	pq.push({4,5,7,89,10,11});
	pq.push({4,5,7,89,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,57,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,57,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});
	pq.push({4,5,7,8,9,10,11});

	auto end = chrono::high_resolution_clock::now();
	cout << "time: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << endl;

	start = chrono::high_resolution_clock::now();

	priority_queue<vector<int>*> pq2;
	pq2.push(new vector<int>({4,5,7,8,9,10,11}));
	pq2.push(new vector<int>({5,5,7,8,9,10,11}));
	pq2.push(new vector<int>({6,5,7,8,9,10,11}));
	pq2.push(new vector<int>({7,5,7,8,9,10,11}));
	pq2.push(new vector<int>({8,5,7,8,9,10,11}));
	pq2.push(new vector<int>({9,5,7,8,9,10,11}));
	pq2.push(new vector<int>({1,5,7,8,9,10,11}));
	pq2.push(new vector<int>({2,5,7,8,9,10,11}));
	pq2.push(new vector<int>({3,5,7,8,9,10,11}));
	pq2.push(new vector<int>({4,5,7,8,9,10,11}));
	pq2.push(new vector<int>({45,7,8,9,10,11,3}));
	pq2.push(new vector<int>({45,7,8,9,10,12,3}));
	pq2.push(new vector<int>({45,7,8,9,10,13,3}));
	pq2.push(new vector<int>({45,7,8,9,10,14,3}));
	pq2.push(new vector<int>({45,7,8,9,10,15,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({47,8,9,10,16,3}));
	pq2.push(new vector<int>({47,8,9,10,16,3}));
	pq2.push(new vector<int>({47,8,9,10,16,3}));
	pq2.push(new vector<int>({478,9,10,16,3}));
	pq2.push(new vector<int>({4,78,9,10,16,3}));
	pq2.push(new vector<int>({4,78,9,10,16,3}));
	pq2.push(new vector<int>({4,78,9,10,16,3}));
	pq2.push(new vector<int>({4,789,10,16,3}));
	pq2.push(new vector<int>({4,7,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,89,10,16,3}));
	pq2.push(new vector<int>({4,7,89,10,16,3}));
	pq2.push(new vector<int>({4,7,89,10,16,3}));
	pq2.push(new vector<int>({4,7,89,11,16,3}));
	pq2.push(new vector<int>({4,7,89,12,16,3}));
	pq2.push(new vector<int>({4,7,89,13,16,3}));
	pq2.push(new vector<int>({4,7,89,14,16,3}));
	pq2.push(new vector<int>({4,7,89,15,16,3}));
	pq2.push(new vector<int>({4,7,89,100,16,3}));
	pq2.push(new vector<int>({4,7,89,10,16,3}));
	pq2.push(new vector<int>({4,7,89,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));
	pq2.push(new vector<int>({4,7,8,9,10,16,3}));

	end = chrono::high_resolution_clock::now();
	cout << "time: " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << endl;

}
