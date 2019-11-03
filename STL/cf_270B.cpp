#include <bits/stdc++.h>

using namespace std;

int a[10005];
int n, countt;

int main() {

    scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//int i = n-1;
	for(int j = 0; j < n-1; j++) {
        if(a[j] > a[j+1]) countt++;
	}
//	while(i > 0 && a[i-1] < a[i]) {
	//	i--;5

wtf;
	//}
	printf("%d", countt);
}
