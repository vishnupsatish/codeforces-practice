/**
 *    author:  vishnus
 *    created: 2022-05-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: binary search for the answer; we know that given an answer, we can
// remove that many ones. Remove the maximum number of ones possible (loop
// how many to remove from the beginning and the end when checking) and check
// whether the number of zeroes remaining is less than or equal to the answer.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<int> op;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        op.push_back(i);
      }
      pref[i + 1] = pref[i] + (s[i] == '0');
    }
    auto Try = [&](int val) -> bool { // Determine if val is a valid answer
      if (val >= (int) op.size()) {
        return true;
      }
      int mz = 1e9;
      int lp = val, rp = 0;
      while (lp >= 0 && rp >= 0) {
        mz = min(mz, pref[op[(int) op.size() - rp - 1] + 1] - pref[op[lp]]);
        lp--;
        rp++;
      }
      return mz <= val;
    };
    int l = 0, r = (int) op.size();
    while (l < r) {
      int mid = (l + r) >> 1;
      if (Try(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l << '\n';
  }
}
