#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> v ,m;
int a[26];
int ans, realans;

int main(){
    int darealans = 1e6+5;
    cin >> s;
    for(int i = 1; i < s.size(); i++) {
        if(s.size() % i == 0) v.emplace_back(i);
    } //10 v contain 1 2 5
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i]; j++) {
            for(int k = j; k < s.size(); k+=v[i]) {
                int temp = s[k];
                a[temp-97]++;
            }
            for(int l = 0; l < 26; l++) {
                ans = max(ans, a[l]);
            }
            ans = s.size() / v[i] - ans ;
            realans += ans;
            ans = 0;
            memset(a,0,sizeof(a));
        }
        darealans = min(realans,darealans);
        realans = 0;
    }

    cout << darealans;
    return 0;
}
