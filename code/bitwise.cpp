#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){

	long z1 = 26; 		// 11010
	unsigned z2 = 16; // 10000
 	short z3 =  4;		//   100	
 	char z4 =  1;			//     1	


	// number of trailing zeroes;
	cout << __builtin_ctz(z1) << endl;	// 1
	cout << __builtin_ctz(z2) << endl;	// 4
	cout << __builtin_ctz(z3) << endl;	// 2
	cout << __builtin_ctz(z4) << endl;	// 0

	// number of leading zeroes up to most significant bit position 
	// (undefined for zero)
	cout << __builtin_clz(z1) << endl;	
	cout << __builtin_clz(z2) << endl;
	cout << __builtin_clz(z3) << endl;
	cout << __builtin_clz(z4) << endl;

	// 8 bytes number
	// 00011111 01111111 01111111 01111111 01111111 01111111 01111111 01111000
	uint64_t zz1 = 2269672922794655608; 
	cout << __builtin_ctzll(zz1) << endl;	// 3
	cout << __builtin_clzll(zz1) << endl;
	cout << __builtin_popcountll(zz1) << endl;


}
