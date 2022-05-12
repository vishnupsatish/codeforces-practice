/**
 *    author:  vishnus
 *    created: 2022-05-12
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: https://imgur.com/a/009bVfT and:
// say s[i] is the largest number that we can remove and s[j] is s[i] + 1 (which cannot be removed). s[j] will
// never be able to be removed since it needs s[i] adjacent to it, but s[i] can only be removed, leading to
// smaller numbers than s[i] being adjacent to s[j], showing that it is optimal to remove s[i]. It is also
// optimal to remove the largest and nothing below since the largest may be neglected if something below is
// removed (since then the largest will be adjacent to something below largest - 1). This shows that removing
// the largest has no negative impact and solely has a positive impact since everything else stays in place
// and can still be removed as before.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (int) (s[i] - 'a');
  }
  auto Find = [&]() {
    for (int i = 25; i >= 0; i--) {
      for (int j = 0; j < (int) a.size(); j++) {
        if (a[j] == i) {
          bool ok = false;
          if (j != 0) {
            ok |= (a[j] == a[j - 1] + 1);
          }
          if (j != n - 1) {
            ok |= (a[j] == a[j + 1] + 1);
          }
          if (ok) {
            return j;
          }
        }
      }
    }
    return -1;
  };
  int ans = 0;
  while (true) {
    int cur = Find();
    if (cur == -1) {
      break;
    }
    a.erase(a.begin() + cur);
    ans++;
  }
  cout << ans << '\n';
}
