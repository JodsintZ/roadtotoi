#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

int n, dp[N][N];
char a[N];

int solve(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];

    int tmp = 0;
    if(l == r) tmp = 0;
    else if(l + 1 == r && a[l] == a[r]) tmp = 1;
    else if(l + 1 == r) tmp = 0;
    else if(a[l] = a[r]) tmp = solve(l+1, r-1)+1;
    else for(int i = l+1; i <= r; i++) tmp = max(tmp, solve(l,i-1)+solve(i,r));
    dp[l][r] = tmp;
    return dp[l][r];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%c", a + i);
    }
    fill_n(dp[0], N*N, -1);
    int ans = solve(0, n-1);
    printf("%d\n", ans);
    return 0;
}