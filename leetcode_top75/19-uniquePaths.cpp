#include <bits/stdc++.h>

using namespace std;

int paths = 0;

int recursiveUniquePaths(int m, int n, int x, int y){
	if ( (m == x) && (n == y) ){
		paths++;
		return 0;
	}
	if (x < m)
		recursiveUniquePaths(m, n, x+1, y);
	if (y < n)
		recursiveUniquePaths(m, n, x, y+1);
}

int dynamicUniquePaths(int m, int n){
	int dp[m][n];
	int i, j;
	
	for (i=0; i< m;i++) {
		for(j=0;j<n;j++) {
			if (i == 0 && j == 0){
				dp[i][j] = 1;
				continue;
			}
			if (i == 0) {
				dp[i][j] = dp[i][j-1];
				continue;
			}
			if (j == 0) {
				dp[i][j] = dp[i-1][j];
				continue;
			}
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	return dp[m-1][n-1];
}

int main(){
	int m = 3, n = 4;
//	int m = 7, n = 3;

	/* recursiveUniquePaths() - consumes 1 auxillay space but time complexity
	 * is higher since it travels through all possible unique paths.
	 * This gives advantage to actually see all unique paths.
	 *
	 * dynamicUniquePaths() - consumes an auxillay space of (m*n) but 
	 * time complexity is greatly managed to O(m+n).
	 */

	recursiveUniquePaths(m, n, 1, 1);
	cout<< paths<<"\n";
	
	// Best Approach
	cout<<dynamicUniquePaths(m, n);
}
