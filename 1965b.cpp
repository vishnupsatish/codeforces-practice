#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used
// Idea: key observation is that the intuitive way to do it is using binary representation. 
// Except, once we are going to hit a sum of k, stop one short. Then, make the next number
// one more, and start doubling the next number. But, we must see that we are missing sums
// here. We are missing k, (k+1)*2-1, (k+1)*3-1. This is because we miss k, so we also miss
// (k+1)+k and an induction follows. So we simply include k*2+1, think of it like having 
// k+1 and k, so by induction every number in that previous sequence can be made except k.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int cur_sum = 0;
    int next_sum = 1;
    int cur = 1;
    bool found = false;
    vector<int> ans;
    while (true) {
      if (next_sum >= k && !found) {
        ans.push_back({k - cur_sum - 1});
        ans.push_back({k + 1});
        cur_sum += k - cur_sum - 1 + k + 1;
        found = true;
        cur *= 2;
      } else {
        if (cur_sum >= n) {
          break;
        }
        ans.push_back({cur});
        cur *= 2;
        cur_sum = cur - 1 - found;
        next_sum = cur * 2 - 1 - found;
      }
    }
    ans.push_back({k * 2 + 1});
    cout << ans.size() << '\n';
    for (int i = 0; i < (int) ans.size(); i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i];
    }
    cout << '\n';
  }
}
