#include<bits/stdc++.h>
using namespace std;

int count_with_prefix(vector<string> v, string prefix);

int main(int argc, char* argv[]){

	vector<string> v1 = {"alpha","baamer","beta","bezos","car"};
	cout << count_with_prefix(v1,"be") << endl;
	vector<string> v2 = {"bee"};
	cout << count_with_prefix(v2,"be") << endl;
	vector<string> v3 = {"cee"};
	cout << count_with_prefix(v3,"be") << endl;
	vector<string> v4 = {"alpha","beamer","beta","bezos","car"};
	cout << count_with_prefix(v4,"be") << endl;


}

int count_with_prefix(vector<string> v, string prefix){
	
	int start = 0;
	int end = v.size()-1;
	int len = prefix.length();

	int mid = (start+end)/2;
	while(start < end){
		cout << start << " " << end << endl;
		if (v[mid].length() >= len && v[mid].substr(0,len) == prefix){
			end = mid;
		}
		else if (v[mid] < prefix)
			start = mid+1;
		else
			end = mid-1;
		mid = (start+end)/2;
	}
	if (v[end].length() < len || v[end].substr(0,len) != prefix)
		return 0;
	int starting_point = end;

	start = 0;
	end = v.size()-1;
	mid = (start+end)/2;
	while(start < end){
		cout << start << " " << end << endl;
		if (v[mid].length() >= len && v[mid].substr(0,len) == prefix){
			start = mid;
		}
		else if (v[mid] < prefix)
			start = mid+1;
		else
			end = mid-1;
		mid = (start+end)/2;
	}
	return start-starting_point+1;
}
