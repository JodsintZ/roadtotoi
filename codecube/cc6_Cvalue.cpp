#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

int n, a[N], dp[N][3];

int main () {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            dp[i][0] = dp[i-1][0] - a[i];
            dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + a[i];
            dp[i][2] = min(dp[i-1][2], dp[i-1][1]) - a[i];
        }
        else {
            dp[i][0] = dp[i-1][0] + a[i];
            dp[i][1] = min(dp[i-1][1], dp[i-1][0]) - a[i];
            dp[i][2] = min(dp[i-1][2], dp[i-1][1]) + a[i];
        }
    }
    printf("%d", min({dp[n][0],dp[n][1],dp[n][2]}));

    return 0;
}
