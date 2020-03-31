#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

struct charFrequency
{
	int freq;
	char c;

	bool operator < (const charFrequency &chr) const
	{ 
		return freq < chr.freq; 
	} 
}; 

void rearrangeString(string str) 
{ 
	int n = str.length();

	int count[MAX_CHAR] = {0}; 
	for (int i = 0 ; i < n ; i++) 
		count[str[i] - 'a']++; 

	priority_queue< charFrequency > maxHeap; 
	for (char c = 'a' ; c <= 'z' ; c++) 
		if (count[c-'a']) 
			maxHeap.push( charFrequency { count[c-'a'], c} ); 

	str = "" ;

	charFrequency prev {-1, '#'} ;

	while (!maxHeap.empty()) 
	{ 
		charFrequency chr = maxHeap.top();
		maxHeap.pop();
		str = str + chr.c; 

		if (prev.freq > 0) 
			maxHeap.push(prev); 

		(chr.freq)--;
		prev = chr;
	}

	if (n != str.length()) 
		cout << "Not possible";

	else
		cout << str;
}

int main() 
{ 
	string str = "aaabbcd";
	rearrangeString(str);
	return 0;
}
