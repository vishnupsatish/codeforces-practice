/**
 *    author:  vishnus
 *    created: 2022-03-28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> nums;
    for (int i = 0; i < n; i++) {
      nums.insert(i);
    }
    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      if (nums.contains(a[i])) {
        nums.erase(a[i]);
      }
      idx[a[i]].push_back(i);
    }
    unordered_set<int> done;
    vector<int> ans(n);
    int cnt = 0;
    unordered_set<int> not_satisfied;
    for (int i = 0; i < n; i++) {
      if (done.contains(a[i])) {
        ans[i] = *nums.begin();
        nums.erase(nums.begin());
        not_satisfied.insert(i);
      } else {
        ans[i] = a[i];
        cnt++;
        done.insert(a[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (ans[i] == i) {
        if (idx[a[i]][0] == i) {
          swap(ans[idx[a[i]][1]], ans[i]);
        } else {
          swap(ans[idx[a[i]][0]], ans[i]);
        }
      }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i] + 1;
    }
    cout << '\n';
  }
}
