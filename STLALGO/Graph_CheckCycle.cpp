#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n, m;
int col[N];
vector<int> g[N], cyc;

void dfs(int u, int p) {
    static vector<int> S;
    col[u] = 1, S.emplace_back(u);
    for(int v : g[u]) if(v != p) {
        if(col[v] == 0) dfs(v, u);
        else if(col[v] == 1) {
            int ptr = S.size() - 1;
            while(cyc.empty() || cyc.back() != v)
                cyc.emplace_back(S[ptr--]);
        }
    }
    col[u] = 2, S.pop_back();
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1, a, b; i <= m; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, 0);

    for(int x : cyc) printf("%d ", x);
    printf("\n");

    return 0;
}
