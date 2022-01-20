#include<bits/stdc++.h>
using namespace std;

void print(auto& v){
	for(auto& x : v){
		cout << x << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]){

	// initialisation using {} 
	vector<int> v1 = {17,11,13,7,5,19,23};
	
	// sorting
	sort(v1.begin(),v1.end());
	print(v1);

	// sorting with lambda - sort in reverse
	// 
	// the 3rd argument is the comparison function that returns
	// true if the first argument is less than the second one
	// to remember, if we want reverse order: (a,b) -> b < a 
	//
	// NOT a stable sort
	sort(v1.begin(),v1.end(),[](int& a, int& b) {
			return b < a;
	});
	print(v1);

	// sorting with lambda - custom sort
	sort(v1.begin(),v1.end(),[](int& a, int& b) {
			if (a % 10 < b % 10)
				return true;
			return false;
	});
	print(v1);

	// sorting pairs: it seems that C++ will sort according to the second
	// pair as well
	vector<pair<int,pair<int,int>>> v2(5);
	v2[0] = make_pair(5,make_pair(4,5));
	v2[1] = make_pair(5,make_pair(1,2));
	v2[2] = make_pair(3,make_pair(5,2));
	v2[3] = make_pair(3,make_pair(2,3));
	v2[4] = make_pair(2,make_pair(1,1));
	sort(v2.begin(),v2.end());

	for(auto& x : v2){
		cout << "(" << x.first << "," << x.second.first << "," << x.second.second << ")" << endl;
	}
	
	// finding an element
	// without auto: vector<pair<int,pair<int,int>>>::iterator f1 = ...
	auto f1 = find(v2.begin(),v2.end(),make_pair(5,make_pair(1,2)));
	cout << typeid(f1).name() << endl;
	cout << "index of item is: " << distance(v2.begin(),f1) << endl; 
	// outputs 3, i.e. 4th element

	// finding an element from the end of the vector (using reverse iterator)
	auto f2 = find(v2.rbegin(),v2.rend(),make_pair(5,make_pair(1,2)));
	cout << "index of item is: " << distance(v2.rbegin(),f2) << endl; 
	// outputs 1, i.e. 2nd element from the back


	// inserting an element
	cout << "Insertion: " << endl << endl;
	
	v1.insert(v1.begin()+1,100);
	print(v1);

	cout << endl;

	// converting from set to vector
	set<int> s = {4,2,3,4,1,4,2,2,2,1};
	v1 = vector<int>(s.begin(),s.end());
	print(v1);


}
