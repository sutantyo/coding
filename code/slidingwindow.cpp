#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	vector<int> arr = {8,5,3,8,2,6,9,11,2,3,7,11,9};
	int sum = 0;
	for(int i = 0; i < 5; i++){
		sum += arr[i];
	}

	int best = sum;
	for(int i = 5; i < arr.size(); i++){
		cout << "current is " << arr[i] << endl;
		sum = sum + arr[i] - arr[i-5];
		cout << sum << endl;
		if (sum > best)
			best = sum;
	}
	cout << best << endl;

}
