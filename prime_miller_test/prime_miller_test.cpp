// only 1 and the prime numbers satisfy the equation
// Miller-test: 2,7,61 enough for p<4*10**9

#include <iostream>

const int fal = 0;
const int tr = 1;

int main(){
	long num;
	int MRprimes[] = {2,7,61};
	int mrValues = sizeof(MRprimes)/sizeof(MRprimes[0]);

	std::cin>>num;
	if ((num==2) || (num==3) || (num==5) || (num==7) || (num==61))
		std::cout<<"Prime: "<< num;
	else if ((num%2==0) || (num%3==0) || (num%5==0) || (num%7==0)) {
		std::cout<<"Not Prime: "<< num;
	}
	else {
		int comp=fal;
		int undef;
		int r=0;
		long d=num-1;
		while (d%2==0) {
			r++;
			d/=2;
		}
		long x,pw,bits;
		for (int i = 0; i < mrValues; i++) {
			x=1;
			pw=MRprimes[i];
			bits=d;
			while (bits!=0) {
				if (bits%2==1) {
					x=(x*pw)%num;
				}
				pw=(pw*pw)%num;
				bits/=2;
			}

			if ((x!=1) && (x!=num-1)) {
				undef=fal;
				for (int j=0;j<r-1;j++) {
					x=(x*x)%num;
					if (x==num-1) {
						undef=tr;
						break;
					}
				}
				if (undef==fal) {
					comp=tr;
					break;
				}
			}
		}

		if (comp==fal) {
			std::cout<<"Prime: "<< num;
		}
	}
}
