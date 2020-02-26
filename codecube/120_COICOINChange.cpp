 #include <bits/stdc++.h>

 using namespace std;

 const int N = 1e6+5;

 int P, M, K;
 int a[11];
 int dp[N] ,pre[N];
 int cur;
 int cnt[15];

 int main(){
    int ans = N;
    for( int i = 0; i < N; i++) {
        dp[i] = N;
    }
    scanf("%d %d %d", &P, &M, &K);
    for(int i = 0; i < K; i++) {
        scanf("%d", a + i);
    }
    dp[0] = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < K; j++) {
            if((i - a[j]) >= 0 ) {
                if(dp[i-a[j]] + 1 < dp[i]) {
                    dp[i] = dp[i-a[j]] + 1;
                    pre[i] = j;
                }
            }
        }
    }
    for(int i = P; i < M; i++) {
        //ans = min(dp[i] + dp[i-P], ans);
        if(dp[i] + dp[i-P] < ans) {
            ans = dp[i] + dp[i-P];
            cur = i;
        }
    }
    int now = cur - p;
    while(now != 0) {
        cnt[pre[now]]++;
        now -= a[pre[now]];
    }

    printf("%d", ans);
    return 0;
 }
