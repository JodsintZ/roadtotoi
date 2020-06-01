#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> v;
int ans, cnt, al, ar;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(auto &a : s) a -= '0'; 

    for(int i = 0; i < 3; i++) {
        al += s[i];
    }
    for(int i = 3; i < 6; i++) {
        ar += s[i];
    }
    if(al == ar) {
        cout << "0" << endl;
        return 0;
    }

    if(al < ar) {
        ans = ar - al;
        for(int i = 0; i < 3; i++) {
            v.emplace_back(9 - s[i]);
        }
        for(int i = 3; i < 6; i++) {
            v.emplace_back(s[i]);
        }
    }

    else {
        ans = al - ar;
        for(int i = 0; i < 3; i++) {
            v.emplace_back(s[i]);
        }
        for(int i = 3; i < 6; i++) {
            v.emplace_back(9-s[i]);
        }
    }

    sort(v.begin(), v.end(), greater<int>());
    //ans = abs(ans);
    //printf("ans = %d " ,ans);
    //for(auto a : v) cout << a << " ";
    /*if(!ans) {
        cout << "0" << endl;
        return 0;
    }
    */
    int i = 0;
    while(i != 6 && ans > 0) {
        ans -= v[i];
        i++;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}