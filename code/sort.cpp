#include<bits/stdc++.h>
using namespace std;

void quicksort(vector<int>&, int, int);
int partition(vector<int>&, int, int);
void swap(vector<int>&, int, int);

void print(vector<int>& a){
	for(auto& x : a){
		cout << x << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]){

	vector<int> a = {3,2,3,1,2,4,5,5,6};
	//print(a);
	quicksort(a,0,a.size()-1);
	print(a);


}

void quicksort(vector<int>& nums, int start, int end){
		if (start >= end)
				return;
		int p = partition(nums, start, end);
		print(nums);
		quicksort(nums,start,p-1);
		quicksort(nums,p+1,end);
}

int partition(vector<int>& nums, int start, int end){
		int pivot = nums[start];

		int f = start+1;
		int l = end+1;

		while(f < l){
				if (nums[f] <= pivot){
						f++;
				}
				else{
						l--;
						swap(nums,l,f);
				}
		}
		swap(nums,start,f-1);
		return f-1;

}

void swap(vector<int> &nums, int a, int b){
		int temp = nums[a];
		nums[a] = nums[b];
		nums[b] = temp;
}



