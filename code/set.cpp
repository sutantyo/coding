#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	set<int> s1 = {7,1,2,3,4,6,8,27,21,22,23,24,26,28,51,52,53,54};
	set<set<int>::iterator> to_remove;

	for(auto it = s1.begin(); it != s1.end(); ){
		if (*it % 2 == 0)
			it = s1.erase(it);
		else
			it++;
	}

	for(auto& x : s1){
		cout << x << " ";
	}
	cout << endl;

	//s1.erase(s1.begin()+5,s1.begin()+8);
	//s1.erase(s1.find(23),s1.find(51));
	auto it = s1.find(23);
	auto it2 = it;
	advance(it2,3);
	s1.erase(it,it2);


	for(auto& x : s1){
		cout << x << " ";
	}
	cout << endl;

	set<int> s2 = {1,2,3};
	set<int> s3 = {2,3,4};
	set<int> temp;
	set_intersection(s2.begin(),s2.end(),s3.begin(),s3.end(),inserter(temp,temp.begin()));


}
