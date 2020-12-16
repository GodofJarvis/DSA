/*
 * https://www.geeksforgeeks.org/coin-change-dp-7/
 *
 * for each coin compute -> number of ways for that coin value upto the amount;
 * dp[am] += dp[am - coin];
 *
 * index - 0 1 2 3 4
 * ways  - 1 1 2 3 4
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> coins = {3,2,1};
    int amount = 4;
    int nCoins = coins.size();

    int amount_dp[amount+1];
    memset(amount_dp, 0, sizeof(amount_dp));
    amount_dp[0] = 1;

    for (int i=0; i<nCoins; i++){
        for (int j=coins[i]; j <= amount; j++){
            amount_dp[j] += amount_dp[ j - coins[i] ];
        }
    }

    cout<<amount_dp[amount];
    return 0;
}
