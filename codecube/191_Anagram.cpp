#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+5;
const int M = 98765431;
char a[N], b[N], n, m;

int main()  {
    scanf("%s %s", a+1, b+1);
	n = strlen(a+1), m = strlen(b+1);
	for(int i = 1; i <= n; i++) a[i] -= 'A';
	for(int i = 1; i <= m; i++) b[i] -= 'A';
	//for(int i = 1; i <= m; i++) printf("%d ",b[i]);;
	int a = comp(n ,m);
    return 0;
}
