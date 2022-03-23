#include <bits/stdc++.h>

using namespace std;

// Idea: for a certain a and b (a > b), an answer exists if we can subtract b some number
// of times from a to get x. To find the next possibility of a and b, set a = b and b =
// a % b since we want to try to make b as a and instead of finding how much we have to
// subtract from a to make it less than b, just take the mod which would be it.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, x;
    cin >> a >> b >> x;
    if (x > max(a, b)) {
      cout << "NO" << '\n';
      continue;
    }
    function<bool(long long, long long)> Do = [&](long long ca, long long cb) {
      if (x == ca || x == cb) {
        return true;
      }
      if (ca == cb) {
        return false;
      }
      if (ca < cb) {
        swap(ca, cb);
      }
      if (cb == 0) {
        return false;
      }
      if ((ca - x) % cb == 0) {
        return true;
      }
      if (ca < x || cb < x) {
        return false;
      }
      return Do(cb, ca % cb);
    };
    cout << (Do(a, b) ? "YES" : "NO") << '\n';
  }
  return 0;
}
