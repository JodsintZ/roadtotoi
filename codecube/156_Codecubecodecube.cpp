#include <bits/stdc++.h>

using namespace std;

int ptr, cnt, j;
string s;
char str[] = "codecube";

int main () {
    cin >> s;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        while(69) {
            if(s[i] == str[j]) {
                j++;
                j %= 8;
                break;
            }
            else {
                j++;
                j %= 8;
                cnt++;
            }
        }
    }

    if(!j) printf("%d\n", cnt);
    else printf("%d\n", cnt+8-j);

    return 0;
}
