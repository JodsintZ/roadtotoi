#include <bits/stdc++.h>

using namespace std;

const int N = 7e3+5;

int n, m, a[N][N], cnt[N], ans[N], ttl;
string s;

int main () {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j+1] = s[j] - '0';
        }
        s.clear();
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j]) {
                a[i][j] += min(a[i-1][j-1], min(a[i-1][j], a[i][j-1]) );
                cnt[a[i][j]]++;
                ttl++;
            }
        }
    }

    for(int i = 1; i <= min(n, m); i++) {
        printf("%d\n", ttl);
        ttl -= cnt[i];
    }
    return 0;
}