#include <bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second

using namespace std;

string S;
vector<int> g;
vector<pii> pp;
int n;

HOW TO USE ITERATOR ON PII WTF

int main() {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> S;
    S += 'K';
    S = 'L' + S; // expand it cuz it can't be 'L' += S;
    cout << S[1];
    n = 5;
    for(int i = 0; i < n; i++) g.emplace_back(i);
    //vector<int>::iterator it = g.end();
    auto it = g.end();
    it--;
    pp.emplace_back(69,70);
    vector<pii>::iterator P = pp.begin();
    printf("\n%d\n", *P);
    printf("\n%d\n", *it);


    return 0;
}