#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e5;
const int M = 98765431; // or 1e9+7;

string s, t;
long hsh[N], anss, anst;

int main() {
    hsh[0] = 1;
    for(int i = 1 ; i < N; i++) hsh[i] = hsh[i-1] * M;
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> t >> s;
    for(int i = 0; i < t.length(); i++) anst += t[i] * hsh[i];
    for(int i = 0; i < s.length(); i++) anss += s[i] * hsh[i];
    if(anst == anss) cout << "yes" << "\n";
    cout << anst << "\n" << anss << "\n";
    for(int i = 0; i < 10; i++) cout << hsh[i] << "\n";
    return 0;
}