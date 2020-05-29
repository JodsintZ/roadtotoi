#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, a, b, c, ans, x, y;
bool john;

int main() {
    scanf("%d", &t);
    while(t--) {
        john = false;
        scanf("%d %d %d %d", &n, &m, &x, &y);
        if(2*x <= y) john = true;
        ans = 0;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int i = 0; i < s.size(); i++) {
                if(john && s[i] == '.') ans += x;
                else if(i != s.size()-1 && !john && s[i] == '.' && s[i+1] =='.') ans += y, i++;
                else if(i != s.size()-1 && !john && s[i] == '.' && s[i+1] == '*') ans += x, i++; 
                else if(i == s.size()-1 && s[i] == '.') ans += x; 
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}