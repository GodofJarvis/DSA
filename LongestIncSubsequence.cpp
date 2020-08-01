#include <bits/stdc++.h>

using namespace std;

int LongestIncSubsequence(int *a, int n){
    if (n == 1)
        return 1;

    int i, j;
    int LIS[n];
    LIS[0] = 1;
    
    for (i=1; i < n; i++) {
        LIS[i] = 1;
        for (j=0; j < i; j++) {
            if ((a[j] < a[i]) && (LIS[i] < LIS[j]+1)) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    
//    for (i=0;i<n;i++)
//        cout<<LIS[i]<<" ";
    return *max_element(LIS, LIS + n);    
}

int main()
{
    int a[] = {5, 2, 3, 10, 15, 11, 13, 14};
    int size = sizeof(a)/sizeof(int);

    cout<<LongestIncSubsequence(a, size);;
    return 0;
}
