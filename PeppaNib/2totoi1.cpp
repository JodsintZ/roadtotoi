#include <bits/stdc++.h>

using namespace std;

int n, maxx = 0;
string s ,ans;
map <string, int> m;

int main(){
    cin >> s;
    cin >> n;
    for(int i = 0; i <= s.size()-n; i++) {
        string temp = "";
        for(int j = 0; j < n; j++) {
            temp += s[i+j];
        }
        m[temp]++;
    }
    string str = "";
    str = str + 'p';
    str = 'a' + str;
    cout << str;
    for(pair<string,int> p : m) {
        if(p.second > maxx) {
            maxx = p.second;
            ans = p.first;
        }
    }
    cout << ans;


    return 0;
}
