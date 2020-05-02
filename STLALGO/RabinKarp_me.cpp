#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e6+5;
const int M = 98765431;

char s[N], sub[N];
int  n, m, cnt;
long mpow[N], hsh[N], pat;

int i, u;

int main() {
    scanf("%d %d",&i, &u);
    scanf(" %s %s", s + 1, sub + 1);
    int n = strlen(s + 1) ;
    int m = strlen(sub + 1) ;
   // cout << n << " " << m;
    mpow[0] = 1;
    for(int i = 1; i < N; i++) { mpow[i] = mpow[i-1] * M; }
    for(int i = 1; i <= n; i++) { hsh[i] = hsh[i-1] + s[i] * mpow[i-1]; }
    for(int i = 1; i <= m; i++) { pat = pat + sub[i] * mpow[i-1] ; }

    for(int i = m; i <= n; i++) {
        long now = hsh[i] - hsh[i - m];
        if(pat * mpow[i-m] == now) cnt++;//printf("pos = %d", i - m +1);
    }

    printf("%d\n", cnt);

    return 0;
}
