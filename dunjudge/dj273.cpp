#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int a[N][N];
int h, w;
long long dp[N][N], ans;

int main() {
    fill_n(dp[0], N*N, -1ll);
    scanf("%d %d", &h, &w);
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= w; i++) {
        dp[1][i] = a[1][i];
    }
    for(int i = 2; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            dp[i][j] = a[i][j] + max({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
        }
    }
    for(int i = 1; i <= w; i++) {
        ans = max(ans,dp[h][i]);
    }
    printf("%lld\n",ans);
    return 0;
}
