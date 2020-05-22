#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+5;
const int M = 5e3;

int n, h, l, r, dp[N][N], a[N], t,ans, prv, e, w;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    scanf("%d %d %d %d", &n, &h, &l, &r);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    fill_n(dp[0], N*N, -1);
  //for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) printf("%d ", dp[i][j]);
    dp[1][a[1]] = 0; 
    if(a[1] <= r && a[1] >= l) dp[1][a[1]]++;
    dp[1][a[1]-1] = 0;
    if(a[1]-1 <= r && a[1]-1 >= l) dp[1][a[1]-1]++;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < h; j++) {
           // printf("%d ", a[i]);
            w = j - a[i];
            while(w < 0) w += h;
            w %= h;
           // printf("%d ", w);
            dp[i][j] = max(dp[i-1][w], dp[i][j]);
           // if( (dp[i][j] != -1) && j <= r && j >= l) dp[i][j] += 1;

            w += 1;
            w %= h;
            dp[i][j] = max(dp[i-1][w], dp[i][j]);
            if( (dp[i][j] != -1) && j <= r && j >= l) dp[i][j] += 1;

        }
    }
    for(int i = 0; i < N; i++) {
        ans = max(ans, dp[n][i]);
    }
   /* for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= h; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    */ 
    printf("%d\n",ans);
    return 0;
}