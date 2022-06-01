/**
 *    author:  vishnus
 *    created: 2022-06-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we can create a system of n equations with n variables (a[0], a[1], ... , a[n - 1]).
// We can begin by taking the sum of a, which is equal to the sum of b divided by (n * (n + 1) / 2).
// This is because when we add all of the equations to one another, we get (n * (n + 1) / 2) 
// as the coefficient for each variable. Then, we loop each i and consider the difference between
// each 'b'. Imagine we are doing a[0] and a[1]. We realize that the difference for each coefficient
// is 1, except for a[1]'s coefficient. This is because a[1] starts at b[1] and cycles back to
// n at a[0]. Then, we realize that we can use simple math to solve for the rest based on the sum
// of all a.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> b(n);
    long long sum_b = 0;
    for (auto &e : b) {
      cin >> e;
      sum_b += e;
    }
    if (sum_b % (n * (n + 1) / 2) != 0) {
      cout << "NO" << '\n';
      continue;
    }
    long long sum_a = sum_b / (n * (n + 1) / 2);
    vector<int> a(n);
    bool ok = true;
    for (int i = 0; i < n; i++) { // Do i and (i + 1) mod n
      if ((b[i] - b[(i + 1) % n] + sum_a) % n != 0) {
        ok = false;
        break;
      }
      a[(i + 1) % n] = (b[i] - b[(i + 1) % n] + sum_a) / n;
      if (a[(i + 1) % n] <= 0) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
}
