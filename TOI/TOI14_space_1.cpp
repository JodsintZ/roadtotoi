#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

int n, m;
string s[N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
            cin >> s[i] 
    }
    for(int i = 1; i < m-1; i++) {
        for(int j = 1; j < n-1; j++) {
            if(s[i][j] == '1') { //upper right left down
                if(s[i+1][j-1] == '1' && s[i+1][j] == '1' && s[i+1][j+1] == '1') utri++, continue;
                if(s[i+1][j+1] == '1' && s[i][j+1] == '1' && s[i-1][j+1] == '1') rtri++, continue;
                if(s[i+1][j-1] == '1' && s[i][j-1] == '1' && s[i-1][j-1] == '1') ltri++, continue;
                if(s[i-1][j-1] == '1' && s[i-1][j] == '1' && s[i-1][j+1] == '1') dtri++, continue;
            }
        }
    }
    return 0;
}