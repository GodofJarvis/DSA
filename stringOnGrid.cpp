#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin>>n>>m;

	int i, j, count=0;
	char a[n][m]={NULL};
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cin>>a[i][j];
		}
	}

/*	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
*/
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){

			if (j+3 < m){
				//cout<<a[i][j]<<" "<<a[i][j+1]<<" "<<a[i][+2j]<<" "<<a[i][j+3]<<"\n";
				if ((a[i][j] == 's') && (a[i][j+1] == 'a') && (a[i][j+2] == 'b') && 
					(a[i][j+3] == 'a')){
						count++;
				}
			}

			if (i+3 < n){
				//cout<<a[i][j]<<" "<<a[i+1][j+1]<<" "<<a[i][+2j]<<" "<<a[i][j+3]<<"\n";
				if ((a[i][j] == 's') && (a[i+1][j] == 'a') && (a[i+2][j] == 'b') && 
					(a[i+3][j] == 'a')){
						count++;
				}
			}

			if ((i+3 <n) && (j+3 < m)) {
				//cout<<a[i][j]<<" "<<a[i][j+1]<<" "<<a[i][+2j]<<" "<<a[i][j+3]<<"\n";
				if ((a[i][j] == 's') && (a[i+1][j+1] == 'a') && (a[i+2][j+2] == 'b') && 
					(a[i+3][j+3] == 'a')){
						count++;
				}
			}

			if ((i-3 >= 0) && (j+3 < m)) {
				//cout<<a[i][j]<<" "<<a[i-1][j+1]<<" "<<a[i-2][j+2]<<" "<<a[i-3][j+3]<<"\n";
				if ((a[i][j] == 's') && (a[i-1][j+1] == 'a') && (a[i-2][j+2] == 'b') && 
					(a[i-3][j+3] == 'a')){
						count++;
				}
			}
		}
	}
	cout<<count;
}
