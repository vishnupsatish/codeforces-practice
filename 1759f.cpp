#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used!!

// Idea: the most important observation is that the overall answer is upper bounded at p - 1; 
// we just increase the units digit and loop it through 0 to one less than what it originally
// was. But, that may not be the optimal answer. The optimal answer may be contributed from 
// the units digit going to 0 and some other digit making up for a certain missing digit. 
// Consider this algorithm. First, go to the highest missing digit in the units digit. Then,
// if there are still digits missing, we know that we have to go to the highest digit that 
// is lower than the units digit through a cycle. So, go to 0, and check if this digit now 
// exists on the board. If it doesn't, must cycle to there. Otherwise, go to the second 
// highest digit that's lower than the original units digit. This works because we know that
// through a carry, only one extra digit will be written on the board.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, p;
    cin >> n >> p;
    vector<int> a(n); // reversed digits; least significant first
    for (int i = 0; i < n; i++) {
      cin >> a[n - i - 1];
    }
    int hi = -1; // Overall highest value
    int hv = -1; // Highest value that is less than the units digit
    int hv2 = -1; // Second-highest value that is less than the units digit
    { // Find highest value
      set<int, greater<>> hs; // Helper set
      for (int i = p - 1; i >= max(0, p - 102); i--) {
        hs.insert(i);
      }
      for (auto e : a) {
        if (hs.contains(e)) {
          hs.erase(e);
        }
      }
      if (!hs.empty()) {
        hi = *(hs.begin());
      }
      if (hi <= a[0]) {
        hi = -1;
      }
    }
    { // Find hv
      set<int, greater<>> hs; // Helper set
      for (int i = a[0] - 1; i >= max(0, a[0] - 102); i--) {
        hs.insert(i);
      }
      for (auto e : a) {
        if (hs.contains(e)) {
          hs.erase(e);
        }
      }
      if (!hs.empty()) {
        hv = *(hs.begin());
        hs.erase(hv);
        if (!hs.empty()) {
          hv2 = *(hs.begin());
        }
      }
    }
    int ans = 0;
    if (hi != -1) {
      ans += (hi - a[0]);
      a[0] = hi;
    }
    if (hv != -1) {
      ans += p - a[0];
      a[0] = 0;
      if (n == 1) {
        a.push_back(0);
        n++;
      }
      a[1]++;
      for (int i = 1; i < n - 1; i++) {
        if (a[i] >= p) {
          a[i + 1]++;
          a[i] = 0;
        }
      }
      if (a[n - 1] >= p) {
        a.push_back(1);
        a[n - 1] = 0;
        n++;
      }
      for (int i = 0; i < n; i++) {
        if (a[i] == hv) {
          hv = hv2;
          break;
        }
      }
      if (hv != -1) {
        ans += hv;
      }
    }
    cout << ans << '\n';
  }
}
