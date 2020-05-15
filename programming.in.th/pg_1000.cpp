#include <bits/stdc++.h>

using namespace std;

int n, m;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        if(i%2) {
            s1.clear();
            cin >> s1;
        }
        else {
            s2.clear();
            cin >> s2;
        }
        if(i) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(s1[i] != s2[i]) cnt++;
            }
            if(cnt > 2) {
                if(i%2) cout << s2 << "\n";
                else cout << s1 << "\n";
                break;
            }
        }

    }
    return 0;
}