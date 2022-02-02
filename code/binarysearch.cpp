#include<bits/stdc++.h>
using namespace std;

int count_with_prefix(vector<string> v, string prefix);
int bin_search(vector<int>&, int);

int main(int argc, char* argv[]){

	vector<int> a = {3,6,9};
	cout << "find 0: " <<  bin_search(a,0) << endl;
	cout << "find 1: " <<  bin_search(a,1) << endl;
	cout << "find 2: " <<  bin_search(a,2) << endl;
	cout << "find 4: " <<  bin_search(a,4) << endl;
	cout << "find 5: " <<  bin_search(a,5) << endl;
	cout << "find 7: " <<  bin_search(a,7) << endl;
	cout << "find 8: " <<  bin_search(a,8) << endl;
	cout << "find 10: " <<  bin_search(a,10) << endl;
	cout << "find 11: " <<  bin_search(a,11) << endl;
	cout << "find 12: " <<  bin_search(a,12) << endl;

	vector<int> b = {3,6,9,12};
	cout << "find 0: " <<  bin_search(b,0) << endl;
	cout << "find 1: " <<  bin_search(b,1) << endl;
	cout << "find 2: " <<  bin_search(b,2) << endl;
	cout << "find 4: " <<  bin_search(b,4) << endl;
	cout << "find 5: " <<  bin_search(b,5) << endl;
	cout << "find 7: " <<  bin_search(b,7) << endl;
	cout << "find 8: " <<  bin_search(b,8) << endl;
	cout << "find 10: " <<  bin_search(b,10) << endl;
	cout << "find 11: " <<  bin_search(b,11) << endl;
	cout << "find 13: " <<  bin_search(b,13) << endl;
	cout << "find 14: " <<  bin_search(b,14) << endl;



	/*
	vector<string> v1 = {"alpha","baamer","beta","bezos","car"};
	cout << count_with_prefix(v1,"be") << endl;
	vector<string> v2 = {"bee"};
	cout << count_with_prefix(v2,"be") << endl;
	vector<string> v3 = {"cee"};
	cout << count_with_prefix(v3,"be") << endl;
	vector<string> v4 = {"alpha","beamer","beta","bezos","car"};
	cout << count_with_prefix(v4,"be") << endl;
	vector<string> v5 = {"alpha","beamer"};
	cout << count_with_prefix(v5,"be") << endl;
	*/


}

int bin_search(vector<int>& nums, int target){
	int first = 0;
	int last = nums.size()-1;
	
	int mid = (first+last)/2;
	while(first <= last){
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			first = mid+1;
		else
			last = mid-1;
		mid = (first+last)/2;
	}
	if (nums[mid] < target)
		return mid+1;
	return mid;
}


int count_with_prefix(vector<string> v, string prefix){
	
	int start = 0;
	int end = v.size()-1;
	int len = prefix.length();

	int res = -1;
	int mid = (start+end)/2;
	while(start <= end){
		if (v[mid].length() >= len && v[mid].substr(0,len) == prefix){
			res = mid;
			end = mid-1;
		}
		else if (v[mid] < prefix)
			start = mid+1;
		else
			end = mid-1;
		mid = (start+end)/2;
	}
	if (res == -1)
		return 0;
	int starting_point = res;

	start = 0;
	end = v.size()-1;
	mid = (start+end)/2;
	res = -1;
	while(start <= end){
		if (v[mid].length() >= len && v[mid].substr(0,len) == prefix){
			res = mid;
			start = mid+1;
		}
		else if (v[mid] < prefix)
			start = mid+1;
		else
			end = mid-1;
		mid = (start+end)/2;
	}
	cout << "    " << starting_point << " " << res << endl;
	return res-starting_point+1;
}
