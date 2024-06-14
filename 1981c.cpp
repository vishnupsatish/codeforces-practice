#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used
// Idea: we can always go down then come back up, as that allows us more choice.
// We would never want to go up then down, or optimally do a zigzag pattern.
// Instead, we would want to find the largest numbers such that the two numbers
// align when repeatedly floor dividing by two (i.e., LCA of the binary tree of
// floor divisions by two, which all meet at 1). If there are remaining values,
// we simply place some placeholder values. There is no chance of two different
// paths, as there is only one way to go down and once it is met, nothing else to do.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    int done = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] != -1) {
        ans[i] = a[i];
        if (i > 0) {
          if (a[i - 1] != -1 && a[i - 1] / 2 != a[i] && a[i] / 2 != a[i - 1]) {
            done = true;
          }
        }
      }
    }
    if (done) {
      cout << "-1\n";
      continue;
    }
    auto FillArbitrary = [&](int l, int r, int value_loc) -> void {
      if (value_loc == -1) {
        for (int i = l; i <= r; i++) {
          ans[i] = (i & 1) + 1;
        }
      } else {
        for (int i = l; i <= r; i++) {
          ans[i] = ((i - value_loc) & 1) ? 2 * a[value_loc] : a[value_loc];
        }
      }
    };
    int prev_idx = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] != -1) {
        prev_idx = i;
        break;
      }
    }
    FillArbitrary(0, prev_idx == -1 ? n - 1 : prev_idx, prev_idx);
    if (prev_idx == -1) {
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << ans[i];
      }
      cout << '\n';
      continue;
    }

    for (int i = prev_idx + 1; i < n; i++) {
      if (a[i] != -1) {
        int cur_i = a[i];
        int cur_prev = a[prev_idx];
        int cnt = 0;
        deque<int> prev_path;
        vector<int> i_path;
        while (cur_i != cur_prev) {
          if (cur_i > cur_prev) {
            cur_i /= 2;
            if (cur_prev != cur_i) {
              i_path.push_back({cur_i});
            }
          } else {
            cur_prev /= 2;
            if (cur_prev != cur_i) {
              prev_path.push_back({cur_prev});
            }
          }
          cnt++;
        }
        --cnt;
        int size = i - prev_idx - 1;
        if ((cnt - size) & 1 || cnt > size) {
          done = true;
          break;
        }
        for (int j = prev_idx + 1; j <= i; j++) {
          if (!prev_path.empty()) {
            ans[j] = prev_path.front();
            prev_path.pop_front();
          } else if (!i_path.empty()) {
            ans[j] = i_path.back();
            i_path.pop_back();
          } else {
            ans[j] = ((j - i) & 1) ? ans[j - 1] * 2 : a[i];
          }
        }
        prev_idx = i;
      }
    }
    if (done) {
      cout << "-1\n";
      continue;
    }
    FillArbitrary(prev_idx + 1, n - 1, prev_idx);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i];
    }
    cout << '\n';
  }
}
