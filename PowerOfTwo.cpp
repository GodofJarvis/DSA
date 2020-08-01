/* Check Power of 2
 * Best time complexity...
 */
 
#include <bits/stdc++.h>

using namespace std;

bool powerof2(int n){
    while (n > 0){
//        cout<<"Debug: Division depth - "<<n<<"\n";
        if (n==1)
            return true;
        else
        if (n & 1)
            return false;
        n = n>>1;
    }
    return false;
}

int main()
{
    int a = 5150;
    if (powerof2(a))
        cout<<"true";
    else
        cout<<"false";
    
    return 0;
}
