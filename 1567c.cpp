/**
 *    author:  vishnus
 *    created: 2022-03-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: recursive backtracking algorithm. Try to not carry the current digit, 
// then try to carry the digit and not carry the next digit. Then try to carry
// the digit and carry the next digit.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    vector<int> sa;
    for (auto c : s) {
      sa.push_back(c - '0');
    }
    function<int(vector<int>, bool, bool)> Do = [&](vector<int> a, bool carry, bool carry2) -> int {
      a[0] -= carry;
      a[1] -= carry2;
      int ans = 1;
      if ((int) a.size() <= 2) {
        for (char c : a) {
          ans *= (c + 1);
        }
        return ans;
      }
      int ret1, ret2;
      ret1 = Do(vector<int>(a.begin() + 1, a.end()), false, false) * (a[0] + 1);
      ret2 = Do(vector<int>(a.begin() + 2, a.end()), true, false) * (9 - a[0]) * (a[1] + 1);
      if (a.size() >= 4) {
        ret2 += (9 - a[1]) * Do(vector<int>(a.begin() + 2, a.end()), true, true) * (9 - a[0]);
      }
      return ret1 + ret2;
    };
    cout << Do(sa, false, false) - 2 << '\n';
  }
}
