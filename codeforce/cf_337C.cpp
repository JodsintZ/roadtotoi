#include <bits/stdc++.h>
#define long long long

using namespace std;

const int M = 1e9+9;
int n, m, k, a, b, c;
long ans;

long modpow(long z, long x) {
    long ret = 1;
    for( ; x; x >>= 1) {
        if(x & 1) ret = ret * z % M;
        z = z * z % M;
    }
    return ret;
}

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    scanf("%d %d %d", &n, &m, &k);
    a = (n/k) * (k-1);
    a += n%k;
  //  printf("a = %d ", a);
    if(a >= m) {
        return !printf("%d\n", m);
    }
    b = m - a;
  //  printf("b = %d ", b );
    ans += modpow(2, b) - 1;
   // printf("pow %d = %lld ", b, ans );
    ans %= M;
    ans *= k;
    ans %= M;
    ans *= 2;
    ans %= M;
    /*
    for(int i = 0; i < b; i++) {
        ans += k;
        ans *= 2;
        ans %= M;
    }
    */
    c = a - (k-1) * b;
    ans += c;
    ans %= M;
    printf("%lld\n", ans);
    return 0;

}