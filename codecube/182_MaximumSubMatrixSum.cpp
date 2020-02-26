#include <bits/stdc++.h>

using namespace std;

int n, h, w, temp;
long long  ansa, ansb;
vector<long long> a, b;

int main() {
    scanf("%d %d %d", &n, &h, &w);

    scanf("%d", &temp);
    a.emplace_back(temp);
    for(int i = 1; i < n; i++) {
        scanf("%d", &temp);
        temp += a[i-1];
        a.emplace_back(temp);
    }

    scanf("%d", &temp);
    b.emplace_back(temp);
    for(int i = 1; i < n; i++) {
        scanf("%d", &temp);
        temp  += b[i-1];
        b.emplace_back(temp);
    }

    if( h == n) ansa = a[h-1];
    else {
        ansa = a[h-1];
        for(int i = 1; i < n - h + 1; i++) {
            ansa = max(ansa , a[h-1+i] - a[i-1]);
        }
    }

    if( w == n) ansb = b[w-1];
    else {
        ansb = b[w-1];
        for(int i = 1; i < n - w + 1; i++) {
            ansb = max(ansb , b[w-1+i] - b[i-1]);
        }
    }

    printf("%lld", ansa*w + ansb*h );
    return 0;
}
