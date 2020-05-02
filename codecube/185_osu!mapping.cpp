#include <bits/stdc++.h>

#define iii tuple<long, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;

int n, m, t, st, en;
long dist[N][8];
vector<pii> g[N];
priority_queue<iii, vector<iii>, greater<iii> > Q;

int main() {
	scanf("%d %d %d %d %d", &n, &m, &t, &st, &en);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].emplace_back(v, w);
	}
	fill_n(dist[0], N*8, 1e12);
	dist[st][0] = 0;
	Q.emplace(dist[st][0], st, 0);
	while(!Q.empty()) {
		iii now = Q.top();
		Q.pop();
		int u = get<1>(now), T = get<2>(now);
		if(get<0>(now) != dist[u][T]) continue;
		for(pii vw : g[u]) {
			int v = vw.x, w = vw.y;
			if(dist[u][T] + w < dist[v][(T+1) % t]) {
				dist[v][(T+1) % t] = dist[u][T] + w;
				Q.emplace(dist[v][(T+1) % t], v, (T+1) % t);
			}
		}
	}
	if(dist[en][t-1] == 1e12) printf("-1\n");
	else printf("%lld\n", dist[en][t-1]);

	return 0;
}
