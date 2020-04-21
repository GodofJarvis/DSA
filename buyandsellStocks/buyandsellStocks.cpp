#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {7,1,5,3,6,4};
//    int a[] = {7,6,4,2,1};
    int n = sizeof(a)/sizeof(int);
   
    int minBuy = INT_MAX;
    int maxSell = 0;
    int maxProfit = 0;
    int profit = 0;
    for (int i=0; i<n; i++){
        if (a[i] < minBuy){
            minBuy = a[i];
        }
        maxSell = a[i];

        profit = maxSell - minBuy;
        if (profit > maxProfit)
            maxProfit = profit;
    }

    cout << maxProfit;
    return 0;
}
