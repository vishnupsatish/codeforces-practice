/**
 *    author:  vishnus
 *    created: 2022-07-14
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: few observations to make here. First, is that all the possible numbers a number
// from multiset 'b' can generate can be found in log^2(number) time; keep dividing by
// two and for every division by two, multiply by two until you hit 1e9. Now, how do we
// know which number from 'b' to associate to a number in multiset 'a', if there are
// two numbers from 'b' that can make the same number from 'a'. It is optimal to take
// the very first number that is found in 'a', since the more you divide, the more number
// from 'b' can eventually get to a number. The less you divide, the less numbers can get
// to a number, so that greedy approach works.

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
    unordered_multiset<int> a, b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.insert(x);
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b.insert(x);
    }
    bool ok = true;
    for (auto e : b) {
      long long cng = e;
      bool done = false;
      while (cng >= 1) {
        long long dcng = cng;
        while (dcng <= (long long) 1e9) {
          if (a.contains(dcng)) {
            a.erase(a.find(dcng));
            done = true;
            break;
          }
          dcng *= 2;
        }
        if (done) {
          break;
        }
        cng /= 2;
      }
      if (!done) {
        ok = false;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
