#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 4;
    int weights[n] = {3, 2, 2, 1};
    int limit = 3;
    
    sort(weights, weights+n);
    
    int i=0, j=n-1, minBoats = 0;
    while(i < j){
        if (weights[j] + weights[i] <= limit){
            i++;
            j--;
        }
        else{
            j--;
        }
        minBoats++;
    }
    if (i == j)
        minBoats++;
        
    cout<<minBoats;
    return 0;
}
