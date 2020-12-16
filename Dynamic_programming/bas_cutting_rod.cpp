/*
 * https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
 *
 * max_cost_dp[length] - for every length compute,
 * max of (current length price + max_cost_dp[length - current_length])
 *
 * For 2d max_cost_dp[length][length] - would be
 * max_cost_dp[i-1][j-curr_length] + current_length_price, max_cost_dp[i-1][j]
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    //vector <int> prices = {5, 1, 1, 1, 1, 1, 1, 1};
    int nlengths = prices.size();
    
    int max_cost_dp[nlengths+1];
    memset(max_cost_dp, 0, sizeof (max_cost_dp));
    max_cost_dp[0] = 0;
    
    for (int length=1; length <= nlengths; length++){
        
        int maxPrice = INT_MIN;
        for (int pr=0; pr<length; pr++){
            maxPrice = max(prices[pr] + max_cost_dp[length - pr -1], maxPrice);
        }
        
        max_cost_dp[length] = maxPrice;
    }
    cout<<max_cost_dp[nlengths];
    
    return 0;
}
