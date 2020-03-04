#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int n, k, p, t, a;
long long pr[N], dp[2][N];

int main() {
    scanf("%d %d %d", &n, &k, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        pr[i] = pr[i-1] + t;
       // cout << a[i] << endl;
    }

    if(k*p >= n) return !printf("%d",pr[n-1] );

    for(int i = 1; i <= k; i++) {
        for(int j = 0; j <= p; j++) dp[a][j] = -1;
        for(int j = p; j <= n; j++) {
        }
        a ^= 1;
    }
    return 0;
}
