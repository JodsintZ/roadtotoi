#include <bits/stdc++.h>

#define long long long

using namespace std;

const int N = 1e5+5;
const long M = 98765431;

int n, m;
vector<int> v;

mt19937 rng(time(NULL));

int main() {   
    for(int i = 0; i < 20; i++) v.emplace_back(i);
    for(int j = 0; j < 40; j++) {
        shuffle(v.begin(), v.end(), rng); 
        printf("\n");
        for(int i = 0; i < 20; i++) printf("%d ", v[i]);
    }
    
    return 0;
}
