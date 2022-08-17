/**
 *    author:  vishnus
 *    created: 2022-08-17
**/
#include <bits/stdc++.h>

using namespace std;

// Vectors which are oppositely directed and collinear will face each other when rotated at 
// some point. Why? Because there is only one possible angle in which they can face other, 
// and this angle is equidistant from both of the vectors, if they are collinear and oppositely directed.

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
    vector<vector<int>> p(n, vector<int>(4));
    map<pair<int, int>, int> vcnt;
    for (int i = 0; i < n; i++) {
      cin >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];
      p[i][2] -= p[i][0];
      p[i][3] -= p[i][1];
      p[i][0] = 0;
      p[i][1] = 0;
      int g = gcd(p[i][2], p[i][3]);
      p[i][2] /= g;
      p[i][3] /= g;
      if (p[i][2] == 0) {
        if (p[i][3] < 0) {
          p[i][3] = -1;
        } else {
          p[i][3] = 1;
        }
      }
      if (p[i][3] == 0) {
        if (p[i][2] < 0) {
          p[i][2] = -1;
        } else {
          p[i][2] = 1;
        }
      }
      vcnt[{p[i][2], p[i][3]}]++;
    }
    long long ans = 0;
    for (auto [nv, cnt] : vcnt) {
      ans += vcnt[{-nv.first, -nv.second}] * (long long) cnt;
    }
    cout << ans / 2 << '\n';
  }
}
