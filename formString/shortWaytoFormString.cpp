#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main()
{
    char source[10] = "abcdef";
    char target[10] = "acfbdae";

//    char source[10] = "abc";
//    char target[10] = "acfbdae";

//    char source[10] = "abc";
//    char target[10] = "abcbc";

//    char source[10] = "xyz";
//    char target[10] = "xzyxz";

    int s_len = strlen(source);
    int t_len = strlen(target);
    
    int i, j, minSubseq = 0;
    for (i=0; i < t_len; ) {
        
        int flag = 0;
        for (j=0; j < s_len;) {
            if (target[i] == source[j]){
                i++;
                j++;
                flag = 1;
            }
            else{
                j++;
            }
            if (i >= t_len)
                break;
        }
        if (flag == 0){
            minSubseq = -1;
            break;
        }
        minSubseq++;
    }

    cout<<minSubseq;
    return 0;
}
