#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 2e3+5;
const int M = 98765431;

char A[N], B[N];
long ha[N], hb[N], Mval[30];

int main() {
    scanf(" %s", A);
    scanf(" %s", B);
    Mval[0] = 1;
    for(int i = 1; i < 30; i++) {
        Mval[i] = Mval[i-1] * M;
    }
    for(int i = 1; i <= A.size(); i++) {
        ha[i] += ha[i-1] + Mval[ A[i-1] - 'A' ];
    }



    return 0;
}