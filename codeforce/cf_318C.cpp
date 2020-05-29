#include <bits/stdc++.h>
#define long long long

using namespace std;

long x, y, m, ans;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> x >> y >> m;
    if(x < y) swap(x, y);
    if(x >= m || y >= m) {
        cout << "0" << endl;
        return 0;
    }
    if(x <= 0 && y <= 0) {
        cout << "-1" << endl;
        return 0;
    }
    while(x < m && y < m) {
        if(y < 0 && x > 0) {
            y = abs(y);
            ans += (y/x) + 1;
            y = -y;
            y += (ans * x);
            continue;
        }
        ans++;
        if(x <= y) x += y;
        else y += x;
    }
    cout << ans << endl;
    return 0;
}