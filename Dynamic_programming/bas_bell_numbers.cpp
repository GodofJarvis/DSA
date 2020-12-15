/*
 * https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
 * 1
 * 1 2
 * 2 3 5
 * 5 7 10 15
 * 15 20 27 37 52
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 5;
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (j==1){
                dp[i][j] = dp[i-1][i-1];
                cout<<dp[i][j]<<" ";
                continue;
            }
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
