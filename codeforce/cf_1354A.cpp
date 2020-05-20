#include <bits/stdc++.h>
#define long long long

using namespace std;

long a, b, c ,d;
int q;

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if(b >= a) {
            printf("%lld\n",b);
            continue;
        }
        if(c <= d) {
            printf("-1\n");
            continue;
        }
        long e = 0, ans = 0;
        ans += b;
        if( (a-b) % (c-d)) e++;
        e += ((a-b) / (c-d) );
        ans += (e * c);
        printf("%lld\n", ans);  
    }

    return 0;
}