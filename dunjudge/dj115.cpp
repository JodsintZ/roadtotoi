#include <bits/stdc++.h>

using namespace std;

deque<int> d;
char a[100001];

int main() {
    int m, k;
    scanf("%d %d", &m, &k);
    scanf(" %s", a);
    for(int i = 0; i < m; i++) {
        d.emplace_back(i);
    }
    for(int i = 0;;i++){
     if(a[i] == 'A') {
        int t;
        t = d.front();
        d.pop_front();
        d.emplace_back(t);
     }
     else if(a[i] == 'B') {
        int t;
        t = d.front();
        d.pop_front();
        int t2 = d.front();
        d.pop_front();
        d.emplace_back(t2);
        d.emplace_front(t);
     }
     else break;
    }

    printf("%d %d %d",d[k-1], d[k], d[k+1]);
}
