#include <bits/stdc++.h>

#define test printf("test\n")
#define long long long
#define tii tuple<int,int,int>
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;

int n, m;
vector<int> g[N];
int chk[N];

void dfs(int x) {
    printf("%d\n", x);
    chk[x] = true;
    for(int e : g[x]) {
        if(!chk[e]) dfs(e);
    }
}

void bfs(int u) {
    queue<int> q;
    q.emplace(u);
    chk[u] = true;
    while(!q.empty()) {
        int now = q.front();
        cout << now;
        q.pop();
        for(int v : g[now]) {
            if(!chk[v]) {
                q.emplace(v);
                chk[v] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    bfs(1);
    printf("\n");
    memset(chk,0,sizeof(chk));
    dfs(1);
    return 0;
}
/*test case
7
1 2
1 3
2 4
2 5
3 6
3 7
7 8
*/
