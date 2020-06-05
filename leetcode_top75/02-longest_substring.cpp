/* Given a string, find the length of the longest substring without
 * repeating characters.
 * 
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a = "abcabde";
    map<char, int> m;
    int result = 0;
    int length=0, j=0;
    
    for (int i=0; a[i]!='\0';){
        if ( m.count(a[i]) ){
            m.erase( a[j++] );
            length--;
        }
        else{
            m.insert({a[i], i});
            length++;
            i++;
            if (length > result)
                result = length;
        }
    }
    cout<<result;

    return 0;
}
