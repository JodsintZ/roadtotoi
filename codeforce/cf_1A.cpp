#include <bits/stdc++.h>

using namespace std;

int n , m ,a;

int main () {
    scanf("%d %d %d", &n, &m, &a);
    int d  = n / a;
    if(n % a != 0) d++;
    int f = m/a;
    if(m%a != 0) f++;
    printf("%d", f * d);
    return 0;
}
