#include <bits/stdc++.h>
#define long long long

using namespace std;

long a, b, c, d;
int t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        printf("%lld\n", (c-a) * (d-b) + 1);
    }
}