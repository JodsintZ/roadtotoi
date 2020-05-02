#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;

vector<int> p({4, 8, 15, 16, 23, 42}), a, s(6);
int n;

int main () {
	scanf("%d", &n);
	for(int i = 0, t; i < n; i++) {
		scanf("%d", &t);
		a.emplace_back(t);
		a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
	}
	//for(int i = 0; i < n; i++) printf("%d ", a[i]);
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			s[0]++;
		} else {
			if (s[a[i] - 1] > 0) {
				s[a[i] - 1]--;
				s[a[i]]++;
			}
		}
	}
	printf("%d\n", n - (s[5] * 6));

	return 0;
}
