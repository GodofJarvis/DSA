#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int solve(){
	int n, m;
	cin>>n>>m;

	char a[n][m];
	int i, j;
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	char str[1000000];
	cin>>str;
	int len = strlen(str);
	
	int k, flag=1;
	for (k=0; k<len; k++) {
		
		i = k % n;
		for (j=0; j<m ; j++) {
			if (a[i][j] == str[k]) {
				a[i][j] = '-';
				break;
			}
			else if (j == m-1){
				flag=0;
			}
		}
		if (flag == 0)
			break;
	}
	if (flag)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}

int main() {
	int t;
	cin>>t;

	while(t--) {
		solve();
	}
}
