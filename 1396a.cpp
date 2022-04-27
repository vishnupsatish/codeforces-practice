/**
 *    author:  vishnus
 *    created: 2022-04-27
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: special case when n == 1. Otherwise, we can first reduce the first number
// to be zero, then do 2, n, and increase each number by (n - 1) * a[i]. This will
// make each number a multiple of n. since (n - 1) * a[i] + a[i] == n * a[i]. Then,
// we just reduce every number by n * a[i], except the first since it is already zero.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << "1 1" << '\n';
    cout << -a[0] << '\n';
    cout << "1 1" << '\n';
    cout << 0 << '\n';
    cout << "1 1" << '\n';
    cout << 0 << '\n';
    return 0;
  }
  cout << "1 1" << '\n';
  cout << -a[0] << '\n';
  cout << "2 " << n << '\n';
  for (int i = 1; i < n; i++) {
    if (i > 1) {
      cout << ' ';
    }
    cout << a[i] * (n - 1);
  }
  cout << '\n';
  cout << "1 " << n << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << (i == 0 ? 0 : a[i] * -n);
  }
  cout << '\n';
}
