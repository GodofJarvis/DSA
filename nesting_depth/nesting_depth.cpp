#include <bits/stdc++.h>

using namespace std;

int paranth(int test){
    char a[101]={NULL};
    char out[100000]={NULL};
    
    cin>>a;
    int i, j, outx=0, pending=0;
    for(i=0; a[i]!='\0'; i++){
        int val = a[i] - '0';

        if (pending > val){
            int close = pending - val;
            pending -= close;
            for (j=0; j < close; j++)
                out[outx++] = ')';
        }
        else if (pending < val){
            int open = val - pending;
            pending += open;
            for (j=0; j < open; j++)
                out[outx++] = '(';
        }
        out[outx++] = a[i];
    }
    for (j=0; j < pending; j++)
        out[outx++] = ')';
    cout<<"Case #"<<test<<": "<<out<<"\n";
}

int main()
{
    int t;
    cin>>t;
    
    int i=1;
    while (t--){
        paranth(i++);
    }

    return 0;
}
