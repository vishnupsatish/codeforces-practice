#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used!!!!

// Idea: clearly a greedy strategy since going to a certain slime removes it (no recurrence 
// or sub problems since there would be information loss, we need to store which slimes are 
// removed). The greedy strategy is to try going both left and right and see that when the 
// current health value is greater than the previous health value, stop! Since increasing 
// health is *always* a good idea; it will always help. If there's no way to increase the 
// health, just go either fully left or fully right, that is the only thing that's optimal.

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    --k;
    vector<int> a(n);
    vector<int> nxt(n, -1), prv(n, -1); // Linked List
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i > 0) {
        nxt[i - 1] = i;
        prv[i] = i - 1;
      }
    }
    int cv = a[k];
    auto NetPositive = [&]() -> int {
      int final_ind;
      int nv = cv;
      int ci = k;
      int okval = cv;
      int lst_work = -1;
      while (nv >= 0) {
        ci = nxt[ci];
        if (ci == -1) {
          return 2;
        }
        nv += a[ci];
        if (nv >= okval) {
          lst_work = ci;
          okval = nv;
        }
      }
      if (lst_work != -1) {
        cv = okval;
        final_ind = lst_work;
        if (nxt[final_ind] == -1) {
          return 2;
        }
        nxt[k] = nxt[final_ind];
        prv[nxt[final_ind]] = k;
        return 1;
      }
      nv = cv;
      ci = k;
      while (nv >= 0) {
        ci = prv[ci];
        if (ci == -1) {
          return 2;
        }
        nv += a[ci];
        if (nv >= okval) {
          lst_work = ci;
          okval = nv;
        }
      }
      if (lst_work != -1) {
        cv = okval;
        final_ind = lst_work;
        if (prv[final_ind] == -1) {
          return 2;
        }
        prv[k] = prv[final_ind];
        nxt[prv[final_ind]] = k;
        return 1;
      }
      return 0;
    };
    int ok = false;
    for (int i = 0; i < n; i++) {
      int val = NetPositive();
      if (val == 0) {
        break;
      }
      if (val == 2) {
        ok = true;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
