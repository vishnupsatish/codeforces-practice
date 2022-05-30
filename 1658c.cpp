/**
 *    author:  vishnus
 *    created: 2022-05-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: only one '1' allowed in c. Cyclically shift c so that the 1 is in the beginning.
// Each element can increase by a maximum of 1 from the previous element, but can decrease
// any amount or stay the same. Why? If c[i] increases (by one), then it means the new
// element is less than the front element of a. If it is the same, it means it is between
// the front element and the next element that contributes the PMA. If it decreases (by x),
// it is between the front and the (x+1)th element that makes a change to the PMA. Using this
// principle, we can figure out a rule for actually forming this permutation. Let's say that
// c[i] represents the PMA number of occurring elements if we take a[i] -> a[0] (reverse).
// For the first occurrence of c[i], we can make a[i] = a[i - 1 - 1 - (number of remaining
// occurrences of c[i]), since we want future occurrences of c[i] (such that it is decreasing)
// to be above the a[i] for the first occurrence of c[i]. For future occurrences of c[i], we
// can set a[i] = previous occurrence of that c[i]'s 'a' value + 1. If c[i] has decreased,
// this ensures that a[i] is greater than the previous value of c[i] but less than the previous
// value of c[i - 1].

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> co(n);
    int op = -1;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      cin >> co[i];
    }
    for (int i = 0; i < n; i++) {
      if (co[i] == 1) {
        if (op != -1) {
          ok = false;
          break;
        }
        op = i;
      }
    }
    if (op == -1) {
      ok = false;
    }
    vector<int> c(n);
    for (int i = op; i < n + op; i++) {
      c[i - op] = co[i % n];
    }
    for (int i = 0; i < n - 1; i++) {
      if (c[i + 1] > c[i] + 1) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
