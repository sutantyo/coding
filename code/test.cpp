#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){


	vector<int> nums = {8, 4, 2, 1};
		unsigned ans=0,mask=0;
    unordered_set<int>st;
   	for(int i=31;i>=0;i--){
       mask|=(1<<i);
       int temp=ans|(1<<i);
			 cout << mask << " " << temp << endl;
			 cout << "ans: " << ans << endl;
       for (int j = 0; j < nums.size(); j++) {
           int num = nums[j] & mask;
					 cout << "    " << num << " size:" << st.size() << endl;
           if (st.find(temp ^ num)!=st.end()) {
                ans = temp;
						 		cout << "         " << (temp^num) << " found so set ans to " << ans << endl;
                break;
           }
						 		cout << "         " << (temp^num) << " not found so insert " << num <<  endl;
           st.insert(num);
       }
      st.clear();
    }
		cout << "answer: " << ans << endl;
   return ans;

}
