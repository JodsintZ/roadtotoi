#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

bool chk[N];
vector<int> g[N];
vector<int> temp;
int n, m, ans;

void dfs(int x) {
    chk[x] = true;
    temp.emplace_back(x);
    for(auto v : g[x]) {
        if(!chk[v]) dfs(v);
    }
}

int main () {
    scanf("%d %d", &n, &m);
    for(int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if(!chk[i]) {
            temp.clear();
            dfs(i);
            bool john = true;
            for(int v : temp) {
                if(g[v].size() != 2) john = false;
            }
            if(john) ans++;
        }
    }

    printf("%d \n", ans);
    return 0;
}
