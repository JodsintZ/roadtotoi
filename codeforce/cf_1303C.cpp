#include <bits/stdc++.h>

using namespace std;
// the idea is the first one is free then the rest check left and right
// , if it's not both then it's a no .else the pointer is change to that one
// just use pointer and shift until it's done, also mark with bool which one already used.
// then print the rest that haven't used yet.
// lmao too lazy to compliment
void solve() {
    string str = "abcdefghijklmnopqrstuvwxyz";
    string s;
    char t[1005];
    cin >> s;
    int cnt[30], ptr;
    memset(cnt, 0, 30); // default as false
    // cout << str << "\n";
    for(int i = 0; i < s.size(); i++) {
        if(i == 0 ) {
            t += s[0];
            ptr = 0;
        }

        if(t[ptr + 1] == s[i]) ptr++;
        else if(t[ptr - 1] == s[i]) ptr--;

        if( (t[ptr + 1] != s[i]) && (t[ptr - 1] != s[i]) && ptr !=0) {
            printf("NO\n");
            break;
        }

        //cnt[s[i] - 'a']++;

    }
}


int main () {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
