/**
*  author:  vishnus
*  created: 2022-08-22
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if the prefix that is to be removed has more than 1 element, just remove one element from there
// and let the prefix remove itself. Otherwise, we want to manually remove the most indices that are a
// part of future prefix, since those elements will be removed anyways. Use a set to do that and remove 
// from the closest future prefix.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[i] = (c == '1');
    }
    deque<pair<int, int>> comp;
    int cur_c = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == cur_c) {
        cnt++;
      } else {
        comp.push_back({cur_c, cnt});
        cur_c = a[i];
        cnt = 1;
      }
    }
    comp.push_back({cur_c, cnt});
    set<int> mult;
    for (int i = 0; i < (int) comp.size(); i++) {
      if (comp[i].second > 1) {
        mult.insert(i);
      }
    }
    int ans = 0;
    int decr = 0;
    while (!comp.empty()) {
      if ((int) comp.size() == 1 && comp[0].second == 1) {
        ans++;
        break;
      }
      if (comp[0].second != 1) {
        ans++;
        comp.pop_front();
        mult.erase(decr);
        decr++;
      } else {
        ans++;
        if (!mult.empty()) {
          int idx = (*mult.begin()) - decr;
          comp[idx].second--;
          if (comp[idx].second == 1) {
            mult.erase(mult.begin());
          }
        } else {
          comp.pop_back();
        }
        comp.pop_front();
        decr++;
      }
    }
    cout << ans << '\n';
  }
}
