#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;

vector <int> g[N];
int n, m, k;
int a[N];

void dfs(int u, int p) {
    a[u] = a[p] + 1;
    for(int v : g[u]) {
        dfs(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int t;
        scanf("%d", &t);
        g[t].emplace_back(i);
    }
    dfs(0,0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, a[i]);
    }
    printf("%d",ans);
}
