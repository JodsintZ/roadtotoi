#include <bits/stdc++.h>

using namespace std;

vector<pair <int, int> > v;
vector<string> a;

int main() {
    int n;
    scanf("%d", &n);
    a.resize(n);
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        int tt;
        scanf("%d", &tt);
        v[i] = pair<int, int>(tt, i);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        cout << a[v[i].second] << "\n";
    }
    return 0;
}
