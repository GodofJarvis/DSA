/* Product of array except self
 * https://leetcode.com/problems/product-of-array-except-self/
 */

#include <bits/stdc++.h>

using namespace std;

vector <int> output;

int product(vector <int> &nums, int itr, int prd){
    if (itr == nums.size()){
        return 1;
    }
    
    int rev;
    if (itr < nums.size()){
        output.push_back(prd);
        prd *= nums[itr];
        rev = product(nums, itr+1, prd);
    }
    
    output[itr] *= rev;
    return rev * nums[itr];
}

vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    if (len < 1)
        return output;
    
    product(nums, 0, 1);
    
/*    output.push_back(1);
    for (int i=1; i<len; i++){
        output.push_back(output[i-1] * nums[i-1]);
    }
    
    int rev = 1;
    for (int i=len-1; i>=0; i--){
        output[i] = output[i] * rev;
        rev = rev*nums[i];
    }
 */   
    return output;
}

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);

    productExceptSelf(input);
    for (int i=0; i<output.size(); i++){
        cout<<output[i]<<" ";
    }
    return 0;
}
