/*
 * https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
 *
 * Use each coin to compute min coins for each amount upto required amount
 */

#include <bits/stdc++.h>

using namespace std;

int main() 
{ 
    vector <int> coins = {3,2,5};
    int amount = 10;
    int minCoins[amount+1];
    memset(minCoins, 0x7F, sizeof(minCoins)); //set close to INT_MAX
    minCoins[0] = 0;

    for (int i=0; i<coins.size(); i++){
        minCoins[coins[i]] = 1;
        for (int j=coins[i]; j<=amount; j++){
            minCoins[j] = min(minCoins[j], minCoins[j-coins[i]] + 1);
        }
    }
    
    cout<<minCoins[amount]<<" ";
    return 0;
}
