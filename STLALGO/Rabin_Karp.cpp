#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e5+5;
const long M = 98765431;

int n, m;
char S[N], P[N];
long mpow[N], hsh[N], pat;

int main() {
    scanf(" %s %s", S + 1, P + 1);
    n = strlen(&S[1]), m = strlen(P + 1);

    mpow[0] = 1;
    for(int i = 1; i < N; i++) mpow[i] = mpow[i-1] * M;
    for(int i = 1; i <= n; i++) hsh[i] = hsh[i-1] + S[i] * mpow[i-1];
    for(int i = 1; i <= m; i++) pat = pat + P[i] * mpow[i-1];

    for(int i = m; i <= n; i++) {
        long now = hsh[i] - hsh[i-m];
        if(pat * mpow[i-m] == now) printf("postion %d\n", i - m + 1);
    }

    return 0;
}
