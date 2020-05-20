#include <bits/stdc++.h>

using namespace std;

const int M = 2e6;

int q;

int main() {
    cin >> q;
    while(q--) {
        int a = 0, b = 0, c = 0, ptr = 0, ans = M;
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') a++;
            else if(s[i] == '2') b++;
            else if(s[i] == '3') c++;

            while( ptr != s.length()-1 && ptr <= i && a && b && c ) {
                ans = min(ans, 1 + i - ptr);
                if(s[ptr] == '1') a--;
                else if(s[ptr] == '2') b--;
                else if(s[ptr] == '3') c--;
                ptr++;
            }
        }
        if(ans == M ) ans = 0;
        cout << ans << endl;

    }
    return 0;
}