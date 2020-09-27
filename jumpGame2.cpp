/* https://leetcode.com/problems/jump-game-ii/
 * LC Hard - Minimum no. of steps to reach last index from first index.
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        if (length < 2)
            return 0;
        if (nums[0] == 0)
            return 0;
        
        int first =0;
        int steps = 0;
        while (first < length-1){
            int maxStep = 0;
            int curr = first;
            if (first+ nums[first] >= length-1){
                steps++;
                break;
            }
            for(int i=curr+1; i <= (curr + nums[curr]); i++){
                if (maxStep < i+nums[i]){
                    maxStep = i+nums[i];
                    first = i;
                }
            }
            steps++;
        }
        return steps;
    }
};
