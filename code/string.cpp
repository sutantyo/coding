#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	string a = "heyllhey";
	auto it = a.find("ll");
	cout << it << endl;
	a.erase(it,it-1);

	cout << a << endl;

}
