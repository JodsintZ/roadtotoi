#include <bits/stdc++.h>
 
#define pii pair<int, int>
#define x first
#define y second
 
using namespace std;
 
const int N = 1e5+5;
 
int n, m, c[N], ptr1, ptr2, ans;
vector<pii> a;
 
int main() {
    scanf("%d %d" ,&n, &m);
    for(int i = 0, C, v; i < n; i++) {
        scanf("%d %d", &C, &v);
        a.emplace_back(v, C);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", c + i);
    }
    sort(c+0, c+m, greater<int>() );
    sort(a.begin(), a.end(), greater<pii>() );
    while(ptr1 != n && ptr2 != m) {
        if(c[ptr2] >= a[ptr1].y) ans++, ptr2++;
        ptr1++;
    }
    printf("%d", ans);
 
}