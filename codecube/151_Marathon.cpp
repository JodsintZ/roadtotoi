#include <bits/stdc++.h>

#define long long long
#define tii tuple<int, int, int>
#define pii pair<int, int>
#define pli pair<long, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;
const long M = 2e18;

int n, m, k, T, l ,r, mid, ans;
vector<tii> g[N];
vector<pii> v, c;
long dp[N];

long dijk(int x) {
    fill_n(dp, N, M);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dp[1] = 0;
    pq.emplace(dp[1], 1);
    while(!pq.empty()) {
        pli now = pq.top();
        pq.pop();
        long dist = now.x;
        int u = now.y;
        if(dist != dp[u]) continue;
        for(auto vw : g[u]) {
            int v = get<0>(vw), d = get<1>(vw), t = get<2>(vw);
            if(d > c[x].y) continue;
            if(dist + t < dp[v]) {
                dp[v] = dist + t;
                pq.emplace(dp[v], v);
            }
        }
    } 
    return dp[n];
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &T);
    for(int i = 0, a, b, d, t; i < m; i++) {
        scanf("%d %d %d %d",&a, &b, &d, &t);
        g[a].emplace_back(b, d, t);
        g[b].emplace_back(a, d, t);
    }
    for(int i = 0, p, s; i < k; i++) {
        scanf("%d %d", &p, &s);
        v.emplace_back(p, s);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i < v.size(); i++){ 
        while(!c.empty() && c.back().x == v[i].x) c.pop_back();
        if(!c.empty() && c.back().x < v[i].x && c.back().y < v[i].y) c.emplace_back(v[i].x, v[i].y);
        if(c.empty()) c.emplace_back(v[i].x, v[i].y);
    }
    //for(auto l : c) printf("%d %d ,", l.x, l.y);
    r = c.size()-1;
    while(l <= r) {
        mid = (l + r) >> 1;
        long dj = dijk(mid);
       // printf("dj = %lld\n", dj);
        if(dj == M || dj > T) l = mid + 1;
        else {
            ans = c[mid].x;
            r = mid - 1;
        }

    }
    if(!ans) return! printf("-1\n");
    printf("%d\n", ans);
    return 0;
}