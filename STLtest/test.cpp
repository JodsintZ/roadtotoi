#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

const int N = 1e5+5;

vector<int> g[N];
bool chk[N];

int dfs(int u) {
    int temp = u;
    printf("%d ", temp);
    chk[u] = true;
    for (int a : g[u]) if(!chk[a]) {
        dfs(a);
    }
}

int bfs(int  u) {
    queue <int> Q;
    Q.emplace(u);
    chk[u] = true;
        while(!Q.empty()) {
            int now = Q.front();
            Q.pop();
            printf("%d ", now);
            for(int i : g[now]) if(!chk[i]){
                Q.emplace(i);
                chk[i] = true;
           }
        }
    printf("\n");
}

int main () {
    int n, e ;
    scanf("%d %d", &n, &e);
    for(int i = 1, a, b; i <= e; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1);
    for(int i = 0; i < N; i++) chk[i] = false;
    cout << endl;

    bfs(1);

    return 0;
}
