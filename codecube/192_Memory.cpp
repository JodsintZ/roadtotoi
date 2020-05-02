#include <bits/stdc++.h>

#define pii pair<int,int>
#define tii tuple<int,int,int>
#define x first
#define y second
#define long long long

using namespace std;

const int N = 5e3+5;
const int M = 2e9;

int n, m, k, a[N], b[N], ans;
int dp[2][N][2]; // opted mem, m, skip 1 yes 0 no

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= m; i++) scanf("%d", b + i);
    for(int i = 1; i <= n; i++) {
        int x = 1&1;
        dp[x][0][0] = 1;
        dp[x][0][1] = 1;
        for(int j = 1; j <= m; j++) {
            dp[x][j][0] = (a[i] = b[j] ? dp[x^1][j-1][0] : M);
            dp[x][j][0] = min(dp[x][j][0], dp[x^1][j-1][0] + 1);
            dp[x][j][0] = min(dp[x][j][0], dp[x][j-1][0] + 1);
            dp[x][j][1] = min(dp[x][j][0] + 1, dp[x^1][j-1][1]);
            dp[x][j][0] = min(dp[x][j][0], dp[x][j][1]);
            if(dp[x][j][0] <= k) ans = max(ans, j);
            if(dp[x][j][1] <= k) ans = max(ans, j);
        }
    }
    printf("%d", ans);
    return 0;
}
