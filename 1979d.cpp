#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used
// Idea: just casework. Key observation is that only two number of contiguous values
// can be different than k, then it's just casework as to what the values can be.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      char b;
      cin >> b;
      a[i] = b - '0';
    }
    // contiguous sequences, 1s or 0s, doesn't matter
    vector<int> con_seq;
    int val = a[0];
    int len = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] != val) {
        con_seq.push_back({len});
        val = a[i];
        len = 1;
      } else {
        len++;
      }
    }
    con_seq.push_back({len});
    int con_len = con_seq.size();
    if (con_seq[con_len - 1] > k) {
      cout << "-1\n";
      continue;
    }
    int wrong = 0;
    int ans = -1;
    int done = false;
    int cur_ind = 0;
    for (int i = 0; i < con_len - 1; i++) {
      if (con_seq[i] != k) {
        wrong++;
        if (con_seq[i] > k) {
          if (con_seq[i] == 2 * k) {
            if (((con_len - 1 - i) & 1) == 0) {
              done = true;
              break;
            } else {
              ans = cur_ind + con_seq[i] / 2;
            }
          } else {
            if (((con_len - 1 - i) & 1) == 1 || (con_seq[con_len - 1] + con_seq[i]) != k * 2) {
              done = true;
              break;
            } else {
              ans = cur_ind + k - con_seq[con_len - 1];
            }
          }
        } else {
          if (((con_len - i - 1) & 1) == 1 || (con_seq[con_len - 1] + con_seq[i]) != k) {
            done = true;
            break;
          } else {
            ans = cur_ind + con_seq[i];
          }
        }
      }
      cur_ind += con_seq[i];
    }
    if (wrong > 1 || done) {
      cout << "-1\n";
    } else if (ans != -1) {
      cout << ans << '\n';
    } else {
      cout << n << '\n';
    }
  }
}
