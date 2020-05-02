#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 2e5+5;

int t, n;
long ans;
map<int,long> m;

int main() {
    scanf("%d", &n);
    for(int i = 1, t, d; i <= n; i++) {
        scanf("%d", &t);
        d = t - i;
        m[d] += 1ll * t;
    }
    for(auto it : m) {
        ans = max(ans, it.second);
    }
    printf("%lld\n", ans);

    return 0;
}
