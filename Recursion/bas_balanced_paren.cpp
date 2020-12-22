/*
 * https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
 *
 * {{{}}} 111222
 * {{}{}} 112122
 * {{}}{} 112212
 * {}{{}} 121122
 * {}{}{} 121212
 */



#include <bits/stdc++.h>

using namespace std;

char a[100];

void gen_possiblities(int n, int open, int close, int pos){
    if (close == n){
        cout<<a<<"\n";
        return;
    }
    if (open < n){
        a[pos]= '1';
        gen_possiblities(n, open+1, close, pos+1);
    }
    if (close < open){
        a[pos]= '2';
        gen_possiblities(n, open, close+1, pos+1);
    }

}

int main()
{
    int n=3;
    gen_possiblities(n, 0, 0, 0);
    return 0;
}
