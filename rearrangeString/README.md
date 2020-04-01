# Rearrange characters in a string such that no two adjacent characters are same

The idea is to create max heap based on the frequency of characters in the string. Then form a new string by 
taking 1 char from heap, thereby decreasing frequency of last character then insert to heap only in next iteration
(this will ensure next element is not same as current element), till heap becomes empty.

### Sample I/O:

Input: "aaabbcd"

Output: "abacdba"
