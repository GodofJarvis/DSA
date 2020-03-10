#include<iostream>
#include<bits/stdc++.h>

int combination(int n, int k)
{
	int fact[n + 1];
	fact[0] = 1;

	for (int i = 1; i <= n; i++)
		fact[i] = i * fact[i - 1];

	return fact[n] / (fact[k] * fact[n - k]);
}

int main()
{
	int n = 10, k = 9;
	std::cout << "Combination of "<< n<<", taken "<< k <<" at a time: "<< combination(n, k);
	return 0;
}
