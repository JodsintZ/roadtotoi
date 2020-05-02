#include <bits/stdc++.h>

using namespace std;

const int N =1e5+5;

vector<int> g[N];
int n;
bool chk[N];

int dfs(int x) {
    chk[x] = 1;
    len[x] = len[par[x]] ++ ;
    for(int v : g[x]) {
        if(!chk[v]) {
            dfs(v);
        }

    }


}

int main () {
    scanf("%d", &n);
    for(int i = 0, a, b; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    dfs(1);
    return 0;
}
