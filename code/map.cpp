#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	map<int,int> m1;
	map<int,int> m2;

	for(int i = 0; i < 10; i++){
		m1[i] = i;
		m2[i] = i;
	}
	cout << (m1 == m2) << endl;
	m1[20] = 10;
	cout << (m1 == m2) << endl;







}
