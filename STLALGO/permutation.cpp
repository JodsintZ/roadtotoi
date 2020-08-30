#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+5;

int n;

int main () {
  int myints[N];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", myints+i);
  }

  sort (myints,myints+n); //must sort first

  cout << "The 3! possible permutations with 3 elements:\n";
  do {
    //cout << myints[0] << ' ' << myints[1] << " " << myints[2] << '\n';
    for(int i = 0; i < n; i++) cout << myints[i] << ' ';
    cout << endl;
  } while ( next_permutation(myints,myints+n) );

  cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  
  return 0;
}
