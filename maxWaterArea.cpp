/* Container with most water
 * https://leetcode.com/problems/container-with-most-water/
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/

#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int size = height.size();
    int max_volume = 0;

    for (int i=0, j=size-1; i<j; ) {
        int volume = min (height[i], height[j]) * (j-i);
        if (volume > max_volume)
            max_volume = volume;
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return max_volume;
}

int main()
{
    vector <int> heights;
    int a[] = {1,8,6,2,5,4,8,3,7};
    int count = sizeof(a)/sizeof(int);
    for (int i=0; i<count; i++)
        heights.push_back(a[i]);

    cout<<maxArea(heights);
    return 0;
}
