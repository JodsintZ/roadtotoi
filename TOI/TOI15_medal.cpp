#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e6+5;
long n, t[N], h[N];
long ans;

int main () {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", t + i);
    for(int i = 1; i <= n; i++) scanf("%lld", h + i);
    sort(t + 1, t + n + 1);
    sort(h + 1, h + n + 1, greater<int>());
    for(int i = 1; i <= n; i++) h[i] += t[i];
    sort(h + 1, h + n + 1);
    ans = h[n] - h[1];
    printf("%lld", ans);
    return 0;
}
