#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, a, b, c, ans;
bool john;

int main() {
    scanf("%d", &t);
    while(t--) {
        john = false;
        scanf("%d %d %d", &n, &m, &k);
        a = n/k;
        if(m <= a) {
            printf("%d\n", m);
            continue;
        }
        b = m - a;
        k--;
        if(b%k) john = true;
        
        b /= k;
        if(john) b++;
        
        printf("%d\n", a - b);
    }
    return 0;
}