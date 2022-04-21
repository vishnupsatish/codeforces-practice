/**
 *    author:  vishnus
 *    created: 2022-04-21
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Special case if every element is the same. Otherwise, use modular arithmetic.
// Take the GCD of the difference array, then find the mod of each element with the GCD
// (will be the same). The GCD is the max GCD that any additions can provide. Then, do
// GCD(gcd value, b[i] + mod value) for the answer. Why? (b[i] + mod value) % gcd value is
// the new mod value, and since GCD(gcd value, b[i] + mod value) will always be a divisor of
// gcd value, it is the greatest value such that it divides each number in the added array.
// This is because when mod value of array 'a' is zero, it means the new value can also
// divide every element (since it's a divisor of the gcd value), but may not be the greatest.
// Why does b[i] + mod value itself not work? Because it may not be a divisor of the gcd value
// meaning that the mod value may not be zero for each element.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n), b(m), dif(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      dif[i - 1] = abs(a[i] - a[i - 1]);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long g = 0;
  for (int i = 0; i < n - 1; i++) {
    if (dif[i] != 0) {
      if (g == 0) {
        g = dif[i];
      } else {
        g = gcd(g, dif[i]);
      }
    }
  }
  if (g == 0) {
    for (int i = 0; i < m; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << a[0] + b[i];
    }
    cout << '\n';
    return 0;
  }
  long long md = a[0] % g;
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << ' ';
    }
    long long cmd = (md + b[i]) % g;
    if (cmd == 0) {
      cmd = g;
    }
    cout << gcd(g, cmd);
  }
  cout << '\n';
}
