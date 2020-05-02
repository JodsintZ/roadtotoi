#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5; // out degree only

long ans[N];
int n, m, deg[N], d[N], chk[N];
vector<vector<pii> > g(N);

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
		deg[u]++, deg[v]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) q.emplace(i);
        d[i] = 1;
	}
	while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto v : g[now]) {
            if(deg[v.x] > 1) {
                ans[v.y] = 1ll * d[now] * (n - d[now]);
                d[v.x] += d[now];
                deg[v.x]--;
                if(deg[v.x] == 1) q.emplace(v.x);
            }
        }
	}
	for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
/*
9 9
1 2 1 3 1 4 2 3 2 5 3 6 6 7 6 8 8 9
*/
