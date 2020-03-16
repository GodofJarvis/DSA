#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m =5, n=5;
    int matrix[5][5];
    
    int i, j, ct=0;
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            matrix[i][j] = ++ct;
        }
    }
    
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\nSpiral matrix: "<< ct<<" numbers\n";
    int leftEdge=0, rightEdge=n-1, upEdge=0, downEdge=m-1;
    while (ct>0){
        i=upEdge;
        for (j=leftEdge; j<=rightEdge; j++){
            cout<<matrix[i][j]<<" ";
            ct--;
            if (j == rightEdge)
                upEdge +=1;
        }
        j--;
        
        if (ct <= 0)
            break;
        for (i=upEdge; i<=downEdge; i++){
            cout<<matrix[i][j]<<" ";
            ct--;
            if (i == downEdge)
                rightEdge -= 1;
        }
        i--;
        
        if (ct <= 0)
            break;
        for (j=rightEdge; j>=leftEdge; j--){
            cout<<matrix[i][j]<<" ";
            ct--;
            if (j == leftEdge)
                downEdge -= 1;
        }
        j++;

        if (ct <= 0)
            break;
        for (i=downEdge; i>=upEdge;i--){
            cout<<matrix[i][j]<<" ";
            ct--;
            if (i == upEdge)
                leftEdge +=1;
        }
    }
    return 0;
}
