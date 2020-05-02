#include <bits/stdc++.h>

#define long long long
#define pii pair<long, int>
#define tii tuple<int,int,int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;
const long M = 2e18+9;

vector<pii> g[N];
//vector<int> par[N];
int a, b, c, d, n, m;
long dp[N], dp2[N], dp3[N];
bool chk[N];

int main () {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    scanf("%d %d %d %d", &a, &b, &c, &d);
    fill_n(dp, N, M);
    fill_n(dp2, N, M);
    fill_n(dp3, N, M);
    //end of input
    priority_queue <pii, vector<pii> , greater<pii>> p;
    dp[a] = 0;
    p.emplace(dp[a], a);
    while(!p.empty()) {
        pii now = p.top();
        p.pop();
        int u = now.y;
        long dist = now.x;
        if(dist != dp[u]) continue;
        for(auto v : g[u]) {
            if(dist + v.y < dp[v.x]) {
                dp[v.x] = v.y + dist;
                p.emplace(dp[v.x], v.x);
            }
        }
    }

    dp2[b] = 0;
    p.emplace(dp2[b], b);
    while(!p.empty()) {
        pii now = p.top();
        p.pop();
        int u = now.y;
        long dist = now.x;
        if(dist != dp2[u]) continue;
        for(auto v : g[u]) {
            if(dist + v.y < dp2[v.x]) {
                dp2[v.x] = v.y + dist;
                p.emplace(dp2[v.x], v.x);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(dp[i] + dp2[i] == dp[b])
        chk[i] = true;
    }
    //dp c to d
    dp3[c] = 0;
    p.emplace(dp3[c], c);
    while(!p.empty()) {
        pii now = p.top();
        p.pop();
        int u = now.y;
        long dist = now.x;
        if(dist != dp3[u]) continue;
        for(auto v : g[u]) {
            if(dist + v.y < dp3[v.x] && !chk[v.x]) {
                dp3[v.x] = v.y + dist;
                p.emplace(dp3[v.x], v.x);
            }
        }
    }
    if(!chk[c] && !chk[d] && (dp3[d] != M ) ) printf("%lld\n", dp3[d]);
    else  printf("-1\n");
    return 0;
}
