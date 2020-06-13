#include <bits/stdc++.h>

using namespace std;

const int MOD = 997;

int n, a[200], tmp[2];

int main() {
    scanf("%d", &n);
    a[0] = 3, a[1] = 2;
    for(int i = 2; i <= 165; i++) {
        a[i] = 3*a[i-1] + 4*a[i-2];
        a[i] %= MOD;
       // printf("%d = %d\n", i, a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", tmp + 0);
        tmp[0] %= 166;
        printf("%d\n", a[tmp[0]]);
    }
    
    return 0;
}