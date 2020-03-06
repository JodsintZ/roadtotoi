#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;

int n, m;
int dp[N];
vector<pii> g[N];
priority_queue<pii, vector<pii>, greater<pii> > Q;

int main() {
    fill_n(dp, N, 1e9);

    scanf("%d %d", &n, &m);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dp[1] = 0;
    Q.emplace(dp[1], 1);
    while(!Q.empty()) {
        pii now = Q.top();
        Q.pop();
        int u = now.y, dist = now.x;
      //  if(dist != dp[u]) continue;

        for(pii v : g[u]) {
            if(dist + v.y < dp[v.x]) {
                dp[v.x] = dist + v.y;
                Q.emplace(dp[v.x], v.x);
            }
        }
    }
    for(int i = 1; i <= n; i++) printf("%d ", dp[i]);
    printf("\n");

    return 0;
}
