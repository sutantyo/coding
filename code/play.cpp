#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	vector<vector<int>> input = {{1,4},{2,5},{3,1},{3,3},{5,1},{5,2},{5,3}};

	sort(input.begin(),input.end(),[](vector<int> a, vector<int> b){
			return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
	});

	for(auto& x : input){
		cout << "(" << x[0] << "," << x[1] << ")" << endl;
	}

}
