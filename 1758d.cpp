#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used!!

// Idea: start with 1 3 5 7 9 ... (which produces a square) 
// and go from there. Simple construction to be honest.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (!(n & 1)) {
      int fst = n / 2;
      for (int i = 0; i < n; i++) {
        cout << fst << ' ';
        fst++;
        if (fst == n) {
          fst++;
        }
      }
      cout << '\n';
    } else {
      int fst = (n + 1) / 2 + 1;
      for (int i = 0; i < n; i++) {
        cout << fst << ' ';
        fst++;
        if (i == n / 2 - 1) {
          fst += 2;
        }
      }
      cout << '\n';
    }
  }
}
