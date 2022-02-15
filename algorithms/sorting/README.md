# Sorting


### Mergesort

```cpp
void mergesort(vector<int>& nums, int start, int end){

    if (start >= end) 
        return;
    int mid = start + (end-start)/2;
    mergesort(nums,start,mid);
    mergesort(nums,mid+1,end);
    merge(nums,start,mid,end);
}

void merge(vector<int>& nums, int start, int mid, int end){

    int l = start;
    int r = mid+1;
    
    vector<int> temp(end-start+1,0);
    int pos = 0;
    while(l <= mid && r <= end){
        if (nums[l] <= nums[r])
            temp[pos++] = nums[l++];
        else
            temp[pos++] = nums[r++];
    }
    while (l <= mid)
        temp[pos++] = nums[l++];
    while (r <= end)
        temp[pos++] = nums[r++];
    for(int i = 0; i < temp.size(); i++){
        nums[start+i] = temp[i];
    }
}
```



