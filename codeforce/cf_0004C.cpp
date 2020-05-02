#include <bits/stdc++.h>

using namespace std;

int n;
string s;
map<string,int> m;

int main () {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> s;
        if(m[s] == 0) {
            printf("OK\n");
            m[s]++;
        }
        else {
            cout<<s<<m[s]<<"\n";
            m[s]++;

        }

    }

    return 0;
}
