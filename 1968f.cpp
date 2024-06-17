#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used
// Idea: key observation is that you can always get k <= 3. If it is 2, then xor 
// of the segment must be 0. Otherwise, we can get 3. To get 3, the xor of each 
// \segment must be equal to the overall xor. Find the first segment that has 
// that xor value using binary search, then find the second, then we are done,
// as the third is guaranteed to have that xor value. One question that could
// be asked is, what if in the initial segment we can't find a later one, but
// there is a later initial one that leads to a correct later one? This can't
// be true because of how xor works, as the "gap" will have an xor of 0, 
// meaning the later later one can extend backwards.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> pxor(n + 1);
    for (int i = 0; i < n; i++) {
      pxor[i + 1] = pxor[i] ^ a[i];
    }
    map<int, vector<int>> vals;
    for (int i = 0; i < n; i++) {
      vals[pxor[i + 1]].push_back({i});
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      --l; --r;
      int target = pxor[r + 1] ^ pxor[l];
      if (target == 0) {
        cout << "YES\n";
        continue;
      }
      int pxor_target = pxor[l] ^ target;
      int fst_idx = lower_bound(vals[pxor_target].begin(), vals[pxor_target].end(), l) - vals[pxor_target].begin();
      if (fst_idx == vals[pxor_target].size() || vals[pxor_target][fst_idx] >= r) {
        cout << "NO\n";
        continue;
      }
      int new_pxor_target = pxor[vals[pxor_target][fst_idx] + 1] ^ target;
      int snd_idx = upper_bound(vals[new_pxor_target].begin(), vals[new_pxor_target].end(), vals[pxor_target][fst_idx]) - vals[new_pxor_target].begin();
      if (snd_idx == vals[new_pxor_target].size() || vals[new_pxor_target][snd_idx] >= r) {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
    }
  }
}
