/**
 *    author:  vishnus
 *    created: 2022-04-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: key thing to note is to use PSA. When there is a particle travelling
// left, it will go left the entire time. Same with right. For each k value, n 
// value, and direction, store how many particles started at that point. Then use
// PSAs for the previous level below. For each particle, it will create another 
// particle of one less decay, same n, and different direction. Answer is sum of all cnt.

const int md = (int) 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    // k, n, dir (k is decay value, n is where it started (before/between planes), dir is which direction it goes.
    vector<vector<vector<long long>>> cnt(k + 1, vector<vector<long long>>(n + 1, vector<long long>(2))); // 0 for right, 1 for left
    cnt[k][1][0] = 1;
    long long ans = 1;
    for (int i = k - 1; i >= 1; i--) {
      vector<long long> prefr(n + 2), prefl(n + 2);
      for (int j = 1; j <= n; j++) {
        prefr[j] = prefr[j - 1] + cnt[i + 1][j][0];
        prefr[j] %= md;
      }
      for (int j = n; j >= 1; j--) {
        prefl[j] = prefl[j + 1] + cnt[i + 1][j][1];
        prefl[j] %= md;
      }
      for (int j = 1; j <= n; j++) {
        if (j != 1) {
          cnt[i][j][0] = prefl[j];
        }
        cnt[i][j][1] = prefr[j];
        ans += (cnt[i][j][0] + cnt[i][j][1]) % md;
        ans %= md;
      }
    }
    cout << ans << '\n';
  }
}
