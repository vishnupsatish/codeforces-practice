/**
 *    author:  vishnus
 *    created: 2022-04-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we should take some amount 1 1s and the rest should be the 
// k - (number of 1 1s taken) 1 0s and 0 1s. Use sorting and prefix sum arrays.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> t(n), a(n), b(n);
  vector<int> pa, pb, pall;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> a[i] >> b[i];
    if (a[i] && b[i]) {
      pall.push_back(t[i]);
    } else if (a[i]) {
      pa.push_back(t[i]);
    } else if (b[i]) {
      pb.push_back(t[i]);
    }
  }
  sort(pall.begin(), pall.end());
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());
  int palls = (int) pall.size();
  int pas = (int) pa.size();
  int pbs = (int) pb.size();
  vector<int> prefall(palls + 1), prefa(pas + 1), prefb(pbs + 1);
  for (int i = 0; i < palls; i++) {
    prefall[i + 1] = prefall[i] + pall[i];
  }
  for (int i = 0; i < pas; i++) {
    prefa[i + 1] = prefa[i] + pa[i];
  }
  for (int i = 0; i < pbs; i++) {
    prefb[i + 1] = prefb[i] + pb[i];
  }
  int ans = 2e9 + 1;
  if (pas >= k && pbs >= k) {
    ans = min(ans, prefa[k] + prefb[k]);
  }
  for (int i = 0; i < (int) pall.size(); i++) {
    if (i > k - 1) {
      break;
    }
    if (pas >= k - i - 1 && pbs >= k - i - 1) {
      ans = min(ans, prefall[i + 1] + prefa[k - i - 1] + prefb[k - i - 1]);
    }
  }
  cout << (ans == 2e9 + 1 ? -1 : ans) << '\n';
}
