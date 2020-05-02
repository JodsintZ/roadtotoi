#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n, m, k;
int dp[N];
vector<int> g[N];

void dfs(int u, int p) {
    for(int v : g[u]) if(v != p) dfs(v, u);
    dp[u] = 1;
    vector<int> vec;
    for(int v : g[u]) if(v != p) vec.emplace_back(dp[v]);
    sort(vec.begin(), vec.end(), greater<int>());
    for(int i = 0; i < k && i < vec.size(); i++) dp[u] += vec[i];
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 2, p; i <= n; i++) {
        scanf("%d", &p);
        g[p].emplace_back(i);
        g[i].emplace_back(p);
    }
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        k = mid;
        dfs(1, 1); //start with root
        if(dp[1] >= m) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);

    return 0;
}
