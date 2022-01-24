#include<bits/stdc++.h>
using namespace std;



void floyd_warshall(vector<vector<double>> rate);

void print(vector<vector<int>> v){
	for(auto& x : v){
		for(auto& y : x){
			cout << y << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<double>> v){
	for(auto& x : v){
		for(auto& y : x){
			printf("%.2f ",y);
		}
		cout << endl;
	}
}

int main(int argc, char* argv[]){

	// suppose we are given the following exchange rate:
	vector<vector<double>> rate = 
							// AUD   USD   GBP   EUR 
		/* AUD */	{{ 1.00, 0.72, 0.56, 0.61 },  
		/* USD */  { 1.33, 1.00, 0.72, 0.92 }, 
	  /* GBP */	 { 1.89, 1.38, 1.00, 1.17 },
		/* EUR */  { 1.52, 1.16, 0.88, 1.00 }};

	// is there arbitrage?

	floyd_warshall(rate);
	

}

void floyd_warshall(vector<vector<double>> rate){
	
	vector<vector<vector<int>>> prev(rate.size(),vector<int>(rate.size())); 
	for(int i = 0; i < prev.size(); i++){
		for(int j = 0; j < prev.size(); j++){
			prev[i][j] = i;
		}
	}
	print(prev);

	for(int k = 0; k < rate.size(); k++){
		for(int i = 0; i < rate.size(); i++){
			for(int j = 0; j < rate.size(); j++){
				double d = rate[i][k] * rate[k][j];
				if (d > rate[i][j]){
					rate[i][j] = d;
					prev[i][j] = k;
				}
			}
		}
		cout << endl << "After " << k << " iteration: " << endl; 
		print(rate);
		cout << endl;
		print(prev);
	}
	print(prev);

}
