#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+5;
const int M = 1e6+7;

int n, m, t, cur;
int a[505];
long long dp[3][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        cur = i&1; //start off 1
        dp[cur^1][0] = 1; //init
        for(int j = 1; j <= m; j++) {
            dp[cur][j] = 0;
            if (a[i] <= j) dp[cur][j] += dp[cur^1][j-a[i]];
            dp[cur][j] += dp [cur^1][j];
            dp[cur][j] %= (1LL * M);
        }
    }
    printf("%lld", dp[n&1][m]);
    return 0;
}
