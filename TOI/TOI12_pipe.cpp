#include <bits/stdc++.h>
#define long long long
using namespace std;
const int N = 15005;
int n, k;
int x[N], y[N], key[N], chk[N];
int main() {
    fill_n(key, N , 2e9);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d %d", x + i, y + i);
    int u = 1;
    chk[1] = true, key[1] = 0;
    for(int step = 1; step <= n; step++) {
        int v = -1, w = 1e9;
        for(int i = 1; i <= n; i++) if(!chk[i]) {
            int dist = abs(x[u] - x[i]) + abs(y[u] - y[i]);
            if(dist < key[i]) key[i] = dist;
            if(key[i] < w) w = key[i], v = i;
        }
        if(v != -1) chk[v] = true, u = v;
    }
    long ans = 0;
    vector<int> vec;
    for(int i = 2; i <= n; i++) vec.emplace_back(key[i]), ans += key[i];
    sort(vec.begin(), vec.end(), greater<int>()); 
    for(int i = 0; i < k - 1; i++) ans -= vec[i];
    printf("%lld\n", ans);
    return 0;
}