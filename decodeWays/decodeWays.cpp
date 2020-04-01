#include <iostream>

using namespace std;
#define N 10

int decodeAllPossibleEncodes(char a[N]){
    int i;
    int ways[N+1];

    // Ways follows 1 index, a follows 0 index
    ways[0] = 1;
    ways[1] = 1;
    for (i=1; a[i]!= '\0'; i++){
        ways[i+1] = ways[i];
       
        int digit = (a[i-1]-'0') * 10;
        digit += (a[i]-'0');
        if (digit < 27)
            ways[i+1] += ways[i-1];
    }
    return ways[i];
}

int main()
{
    char a[N] = "1235226";
//    char a[N] = "12122";
//    char a[N] = "521";
    cout<< decodeAllPossibleEncodes(a);
    return 0;
}
