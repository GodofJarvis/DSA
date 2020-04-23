#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m = 3, n =3;
    int i, j;
    int a[m][n] = {
        {1,3,1},
        {1,5,1},
        {3,2,1}};

/* This problem can also be solved by top down approach.
 *
 * Below implementation is using bottom up manner, this
 * will give advantage to find minimum cost between all
 * nodes (as source) and destination.
*/
    int minCost[m][n] = {0};
    minCost[m-1][n-1] = a[m-1][n-1];

    for (i=m-1; i>=0; i--) {
        for (j=n-1; j>=0; j--) {
            if ((i < m-1) && (j < n-1)){
                minCost[i][j] = a[i][j] + min(minCost[i][j+1], minCost[i+1][j]);
            }
            else if (j < n-1) {
                minCost[i][j] = a[i][j] + minCost[i][j+1]; 
            }
            else if (i < m-1) {
                minCost[i][j] = a[i][j] + minCost[i+1][j];
            }
        }
    }

    cout<<minCost[0][0];
/*    for (i=0; i < m; i++){
        cout<<"\n";
        for (j=0; j < n; j++){
            cout<<minCost[i][j]<<" ";
        }
    }
*/
    return 0;
}
