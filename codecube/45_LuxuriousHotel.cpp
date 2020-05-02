#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e5+5;
const int M = 2e9;

int n, p, k;
int a[N], dp[2][N];

int main () {
    scanf("%d %d %d", &n, &k, &p);
    for(int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        a[i] = a[i-1] + t;
    }
    //cout << a[n] << "\n" ;
    if(k*p >= n) return !printf("%d", a[n]);

    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < p; j++) dp[i&1][j] = - M;
        for(int j = p; j <= n; j++) dp[i&1][j] = max(dp[(i & 1)][j-1], dp[(i+1) & 1][j-p] + a[j] - a[j-p]);
    }
    //cout << dp[1][n] << " ";
    //cout << dp[0][n]<< " ";
    printf("%d \n", max(dp[1][n], dp[0][n]) );
    return 0;
}


