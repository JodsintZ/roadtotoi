#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, mx = 1e9, my = 1e9;
int g[N * N][4], x[N * N], y[N * N], ans[N][N];

void dfs(int u, int p) {
    mx = min(mx, x[u]), my = min(my, y[u]);
    for(int i = 0; i < 4; i++) if(g[u][i]) {
        int v = g[u][i];
        if(v == p) continue;
        x[v] = x[u] + dx[i], y[v] = y[u] + dy[i];
        dfs(v, u);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i < n * m; i++) {
        int a, b; char T;
        scanf("%d %c %d", &a, &T, &b);
        ++a, ++b;
        if(T == 'U') g[a][0] = b, g[b][2] = a;
        else g[a][1] = b, g[b][3] = a;
    }
    dfs(1, 0);
    for(int i = 1; i <= n * m; i++)
        ans[x[i] - mx + 1][y[i] - my + 1] = i - 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    
    return 0;
}