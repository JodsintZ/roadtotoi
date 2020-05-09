#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e5+5;
const int M = 1e9+9;

int n, m ,ptr;
long po[N], hsh[N], ans;
vector<int> g[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1, a, b; i <= m; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
      //hashing po default
    po[0] = 1;
    for(int i = 1; i < N; i++) {
        po[i] = po[i-1] * M;
    }

    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    //hashing case 1
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            hsh[i] += po[j] * g[i][j];
        }
    }
    sort(hsh + 1, hsh + n + 1);
   /* for(int i = 1; i <= n; i++) {
        printf("%lld\n", hsh[i]);
    }
    */
    for(int i = 1, j = 1; j <= n;) {
        while(j <= n && hsh[i] == hsh[j]) ++j;
        ans += 1ll * (j - i) * (j - i - 1) / 2;
        i = j;
    }

    //  case 2 start here

    for(int i = 1; i <= n; i++) g[i].emplace_back(i);
    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    //hashing case 2
    for(int i = 0 ; i < N; i++) {
        hsh[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            hsh[i] += po[j] * g[i][j];
        }
    }
    sort(hsh + 1, hsh + n + 1);
    
     for(int i = 1, j = 1; j <= n; ) {
        while(j <= n && hsh[i] == hsh[j]) ++j;
        ans += 1ll * (j - i) * (j - i - 1) / 2;
        i = j;
    }

    printf("%lld\n", ans);

    return 0;
}