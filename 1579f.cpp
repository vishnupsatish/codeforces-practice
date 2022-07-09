/**
 *    author:  vishnus
 *    created: 2022-07-09
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: zero is kind of like a "disease vector". When we reach a zero at a certain 
// cycle, we know all elements in that cycle will reach zero. Otherwise, if a cycle 
// only consists of ones, all of the elements will remain ones. In such a case, the 
// answer is -1. We know that the ith value depends on the (i+d)%n-th value. If the 
// (i+d)%n-th value becomes a zero in one step, then the ith value will become a zero
// in two steps. This is similar to a linked list. The answer, thus, is the max value
// of the distance from a one from a zero. 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> vis(n);
    bool ok = true;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        int cur = i;
        bool z = false;
        int cnt = 0;
        do {
          vis[cur] = 1;
          if (a[cur] == 1) {
            cnt++;
            ans = max(ans, cnt);
          } else {
            cnt = 0;
          }
          if (a[cur] == 0) {
            z = true;
            break;
          }
          cur = (cur + d) % n;
        } while (cur != i);
        if (!z) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
}
