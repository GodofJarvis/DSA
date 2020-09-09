/* Largest Rectangle in Histogram
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 */

    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        if (length == 0)
            return 0;

        int stackIndex[length], top=-1;
        int area=0, maxArea=0;
        int i;
        for (i=0; i<length; ){
            if (top ==-1 || heights[i] >= heights[stackIndex[top]]){
                stackIndex[++top] = i;
                i++;
            }
            else{
                int val = heights[stackIndex[top--]];
                if (top == -1)
                    area = val * i;
                else
                    area = val * (i - stackIndex[top]-1);
                maxArea = max(area, maxArea);
            }
        }
        
        while (top >= 0){
            
            int val = heights[stackIndex[top--]];
            cout<<val<<" ";
            if (top == -1)
                area = val * i;
            else
                area = val * (i - stackIndex[top] - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
