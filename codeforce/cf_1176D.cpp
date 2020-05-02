#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

vector<int> v;
int p[N];
int chk[2750135];

void prime() {
    for(int i = 2; i < 2750135; i += j) {

        if(!chk[i]){
            p[j++] = i;
        }

    }

}

int main() {
    scanf("%d", &n);
    for(int i = 0, t; i < 2*n; i++) {
        scanf("%d", &t);
        v.emplace_back(t);
    }
    prime();


    return 0;
}
