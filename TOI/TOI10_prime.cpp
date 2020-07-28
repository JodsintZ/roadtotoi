#include <bits/stdc++.h>

using namespace std;

const int ub = 9e6;
bitset<ub> fac;
int arr[500000], ptr, n;

int main() {
    //pre calculation
	arr[ptr++] = 2; 
	for(int i = 3; i <= ub; i++) {
		if(!fac[i] && i%2 != 0) {
			if(ptr == 500000)	break;
			arr[ptr++] = i;
			for(int j = i; j <= ub; j+=i) {
				fac[j] = true;
			}
		}
	}

	scanf("%d", &n);
	printf("%d\n", arr[n-1]);
	
	return 0;
}