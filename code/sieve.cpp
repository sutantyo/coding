#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	int n = 100;
	vector<bool> isPrime(n,true);

	for(int i = 2; i * i < n; i++){
		cout << i << endl;
		if (!isPrime[i])
			continue;
		for(int j = i*i; j < n; j+=i){
			cout << "  i: " << i << ", j: " << j << endl;
			isPrime[j] = false;
		}
	}

}
