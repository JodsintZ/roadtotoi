#include <bits/stdc++.h>

#define pii pair<int,int>
#define tii tuple<int,int,int>
#define x first
#define y second
#define long long long

using namespace std;
//just realized it's unfinished
const int N = 1e4+5;
const int M = 1e5+5;

int n, s, t, r, path[N];
long ans, dp[N], a[N];
vector<pii> g(N);
pii par[N];

int dfs(int u, int p) {
    for(pii v : g[u]) if(v.x != p) {
        par[x.x] = pii(u, v.y);
        dfs(v.x, u);
    }

}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < N; i++) par[i] = i;
    for(int i = 1, a, b, c; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace(b, c);
        g[b].emplace(a, c);
    }
    for(int i =1; i <= n; i++) {
        scanf("%d", a + i);
    }
    scanf("%d %d %d", &s, &t, &r); // start end key
    //end of input
    par[s] = 0;
    dfs(s, par[s]); // s to t
    for(int i = t; par[i].x; i = par[i].x) path[i] = 1;
    path[s] = 1;

    printf("%lld", ans);
    return 0;
}
