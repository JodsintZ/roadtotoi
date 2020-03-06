#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n, m;
bool chk[N];
vector<int> g[N];

void dfs(int u) { //Depth first search
    printf("%d ", u);
    chk[u] = true;
    for(int v : g[u]) if(!chk[v]) {
        dfs(v);
    }
}

void bfs(int u) {
    queue<int> Q;
    Q.emplace(u);
    chk[u] = true;
    while(!Q.empty()) {
        int now = Q.front();
        Q.pop();
        printf("%d ", now);
        for(int v : g[now]) if(!chk[v]) {
            Q.emplace(v);
            chk[v] = true;
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m); //n = V(G), m = E(G)
    for(int i = 1, a, b; i <= m; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1);
    printf("\n");
    memset(chk, false, sizeof chk);
    bfs(1);

    return 0;
}
