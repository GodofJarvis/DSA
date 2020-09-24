/* https://leetcode.com/problems/decode-string/
 * Input: "3[a]2[bc]"
 * Output: "aaabcbc"
 */
    
    string decodeString(string s) {
        int len = s.length();
        if (len == 0)
            return "";
        
        vector <int> stak;
        int top=0;
        for (int i=0; i<len;i++){
            if (s[i] == ']'){
                vector <char> temp;
                while (stak[--top] != '['){
                    temp.push_back(stak[top]);
                    stak.pop_back();
                }
                stak.pop_back();
                
                string pattern(temp.begin(), temp.end());
                reverse(pattern.begin(), pattern.end());
                temp.clear();
                while (top>0 && (stak[top-1] >='0' && stak[top-1] <= '9')){
                    temp.push_back(stak[--top]);
                    stak.pop_back();
                }
                string count(temp.begin(), temp.end());
                reverse(count.begin(), count.end());
                int ct = stoi(count);
                for (int j=0; j<ct; j++){
                    for (int k=0; k<pattern.length(); k++){
                        stak.push_back(pattern[k]);
                        top++;
                    }
                }
            }
            else{
                stak.push_back(s[i]);
                top++;
            }
        }
        string result(stak.begin(), stak.end());
        return result;
    }
