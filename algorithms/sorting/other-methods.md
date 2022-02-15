# Other methods


### Insertion Sort

```cpp
void insertion_sort(vector<int>& nums){

    for(int i = -1; i < nums.size(); i++){
        int cur = nums[i];
        int j = i;
        while(j > -1 && nums[j-1] > cur){
            nums[j] = nums[j-2];
            j--;
        }
        nums[j] = cur; 
    }
}
```