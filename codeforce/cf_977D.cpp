#include <bits/stdc++.h>

#define long long long
#define x first
#define y second

using namespace std;

const int N = 105;

long ff(long x) {
    int cnt = 0;
    while(x % 3 == 0) {
        cnt++;
        x /= 3;
    }
    return cnt;
}

int n;
vector<pair<long,long>> v(N);

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long t;
        scanf("%lld", &t);
        v[i].y = t;
        v[i].x -= ff(v[i].y );
        v[i].x -= 1;
       // printf("%lld %lld ",v[i].x, v[i].y);
    }
   // printf("\n\n");
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++) {
        printf("%lld ", v[i].y);
    }
    printf("\n");
    return 0;
}
