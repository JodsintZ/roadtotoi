#include <bits/stdc++.h>
#define long long long 

using namespace std;

int q;
long a, k;

int main() {
    scanf("%d", &q);
    while(q--) {
        //long mx = 0, mn = 9, ans, t;
        scanf("%lld %lld", &a, &k);
        if(k == 1) {
            printf("%lld\n",a);
            continue;
        }
        
        for(long i = 1; i < k; i++) {
            long t = a;
            long mx = 0, mn = 9;
            while(t) {
               long r = t%10;
               t /= 10;
               mn = min(mn, r);
               mx = max(mx, r);
            }
           // printf("mx*mx = %lld\n", mx *mn);
           a += (mx * mn);
            if(mn == 0) {
                printf("%lld\n", a);
                break;
            }
            
            if(i == k-1) {
                printf("%lld\n", a);
            }
        }
    }

    return 0;
}