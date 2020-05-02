#include <bits/stdc++.h>

using namespace std;

set<int> s;
int t1;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &t1);
        s.emplace(t1);
        }
        printf("%d", s.size());
}
