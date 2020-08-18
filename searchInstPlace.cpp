int searchInsert(vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 0)
        return 0;

/*        int i;
        for (i=0; i<len; i++){
            if (nums[i] >= target)
                return i;
        }
        return i;
*/
        
    int i=0, j=len-1, pos;
    while (target >= nums[i] && target <= nums[j]){
        
        if (j-i == 1 && target > nums[i] && target <= nums[j]) {
            return j;
        }
        pos = (i+j)/2;
        if (nums[pos] == target)
            return pos;
        if (nums[pos] > target){
            j = pos;
        }
        if (nums[pos] < target){
            i = pos;
        }
    }
    if (target > nums[j])
        return j+1;
    return i;
}
