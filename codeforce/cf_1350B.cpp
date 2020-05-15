#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int q, n, dp[N], a[N], ans;

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &n);
        ans = 0;
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            dp[i] = 1;
        }
        if(n == 1) {
            printf("1\n");
            continue;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                if(i == j) continue;
                if(i % j == 0 && a[i] > a[j]) dp[i] = max(dp[i],dp[j]+1);
                if(i % j == 0 && a[i] > a[i/j]) dp[i] = max(dp[i], dp[i/j] +1); 
            }
           // if(i % 2 == 0 && a[i] > a[i/2]) dp[i] = max(dp[i], dp[i/2] + 1);
        }
        for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        printf("%d\n", ans);

    }

    return 0;
}