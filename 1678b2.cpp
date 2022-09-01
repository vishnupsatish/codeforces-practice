
/**
*  author:  vishnus
*  created: 2022-09-01
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if a 01 or 10 exists in an even position, we must change it since every block must be even-sized.
// Now the question arises, what to change it to? Well, we can greedily change it to the value of the next
// pair for numbers that do not require a change. So, it wouldn't contribute to the answer.

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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - '0';
    }
    int op = 0, ss = 0, cur = -1;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == a[i + 1]) {
        ss += cur != a[i];
        cur = a[i];
      } else {
        op++;
      }
    }
    cout << op << ' ' << max(1, ss) << '\n';
  }
}
