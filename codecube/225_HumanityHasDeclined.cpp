#include <bits/stdc++.h>

#define long long long
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define x first
#define y second

using namespace std;

const int N = 2e5+5;

int n, k, q, t, cnt[N], a[N], vis[N];
vector<int> v;

int main() { 
    scanf("%d %d %d", &n, &k, &q);
    for(int i = 0, z; i < n; i++) {
        scanf("%d", &z);
        v.emplace_back(z);
    }
    for(int i = 0, j = 0 ; j < n; j++) {
        ++cnt[v[j]];
        if(cnt[v[j]] == 1 && v[j] <= k) t++;
        while(t == k && i < n) {
            a[i] = j;
            vis[i] = true;
            if(v[i] > k) {
                ++i;
                continue;
            }
            cnt[v[i]]--;
            if(!cnt[v[i]] && v[i] <= k) t--;
            ++i;
        }

    }
  // for(int i = 0; i < n; i ++) printf("%d %d\n", i, a[i]);

    for(int i = 0, b, c; i < q; i++) {
        scanf("%d %d", &b, &c);
        --b; --c;
        if( ( a[b] == 0 && vis[b]) || ( a[b] != 0 && a[b] <= c) ) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}