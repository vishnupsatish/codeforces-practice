/**
 *    author:  vishnus
 *    created: 2022-05-26
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: greedy. for each element, determine how much we would save by skipping that
// element. That is equal to a[i] - number of remaining elements, since we would have
// to add one to all of the remaining elements. Sort by the greatest of these values,
// then skip over those values. We can imagine this as adding n - i - 1 damage
// immediately after skipping an element. For the first element, the amount of damage
// will be greater by k - 1 (since we will skip over k - 1 elements after this), for
// the second, it will be k - 2, and so on. Thus, the total damage is overcounted by
// k * (k - 1) / 2 which is a constant, so this strategy works.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int>> av(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      av[i] = {a[i] - (n - i - 1), i};
    }
    sort(av.begin(), av.end(), greater<>());
    vector<int> idx(n);
    for (int i = 0; i < k; i++) {
      idx[av[i].second] = 1;
    }
    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (idx[i]) {
        cnt++;
      } else {
        ans += a[i] + cnt;
      }
    }
    cout << ans << '\n';
  }
}
