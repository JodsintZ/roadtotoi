#include <bits/stdc++.h>

using namespace std;

int q;

int main () {
    scanf("%d", &q);
    while(q--) {
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0, cnt = 0; i < s.size(); i++) {
            if(s[i] == 'L') {
                cnt ++;
            }
            else cnt = 0;
            ans = max(ans, cnt);
        }
        printf("%d\n", ++ans);
    }

    return 0;
}
