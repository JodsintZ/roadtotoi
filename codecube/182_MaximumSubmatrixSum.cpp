#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n, h, w;
long long ansa, ansb;
long long a[N], b[N];

int main () {
    ansa = -1;
    ansb = -1;
    a[0] = 0;
    b[0] = 0;
    scanf("%d %d %d", &n, &h, &w);
    for(int i = 1, t = 0; i <= n; i++) {
        scanf("%d", &t);
        a[i] = t + a[i-1];
    }
    for(int i = 1, t = 0; i <= n; i++) {
        scanf("%d", &t);
        b[i] = t + b[i-1];
    }

    for(int i = 1; i <= n-h+1; i++) {
        ansa = max(ansa, a[i + h - 1] - a[i-1]);
    }
    for(int i = 1; i <= n-w+1; i++) {
        ansb = max(ansb, b[i + w - 1] - b[i-1]);
    }
    printf("%lld", ansa*w + ansb*h);

    return 0;
}
