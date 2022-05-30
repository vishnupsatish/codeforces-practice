/**
 *    author:  vishnus
 *    created: 2022-05-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Create plus and minus prefix sum arrays. Loop all subarrays. Since we want pluses and
// minuses to be equal in a subarray, subtract the number of minuses by the number of pluses.
// Let this number be m. We want to be able to form a balanced sequence from just m minuses.
// When we combine two minuses, the difference between the number of pluses and minuses increases
// 3. So, m % 3 == 0 if it is possible. Another way to think about it is we need to be able
// to set m to 2x + x, and all of the '2x's will be turned into pluses, so 2x + x = 3x. Therefore,
// m % 3 == 0.  Also, if the number of minuses - pluses >= 2, there is guaranteed to be more
// than or equal to two minuses beside each other. (Pigeonhole principle I think?)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> m(n + 1), p(n + 1);
    for (int i = 0; i < n; i++) {
      m[i + 1] = m[i] + (s[i] == '-');
      p[i + 1] = p[i] + (s[i] == '+');
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (m[j + 1] - m[i] >= p[j + 1] - p[i] && ((m[j + 1] - m[i] - (p[j + 1] - p[i])) % 3 == 0)) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
