/**
 *    author:  vishnus
 *    created: 2022-08-17
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we know that most of the numbers will directly have to be set to 1. So which numbers should 
// we set to 2 then 1? Well, take the largest number, and find the smallest number such that dividing
// the largest by it twice gives 1. This will be ceil(sqrt(largest number)). We can do this recursively.
// It will be n + log(log(n)). Why? Because continual sqrts (like 2^16, 2^8, 2^4, etc.) has the exponent
// itself decreasing by log.

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
    vector<pair<int, int>> steps;
#ifndef ONLINE_JUDGE
    vector<int> test(n);
    for (int i = 0; i < n; i++) {
      test[i] = i + 1;
    }
#endif
    function<void(int)> Solve = [&](int R) {
      if (R == 2) {
        return;
      }
      int nxt = ceil(sqrt(R));
      for (int i = nxt + 1; i < R; i++) {
        steps.push_back({i, R});
#ifndef ONLINE_JUDGE
        test[i - 1] = 1;
#endif
      }
      steps.push_back({R, nxt});
      steps.push_back({R, nxt});
#ifndef ONLINE_JUDGE
      test[R - 1] = 1;
#endif
      Solve(nxt);
    };
    Solve(n);
#ifndef ONLINE_JUDGE
    assert((int) steps.size() <= n + 5);
    int ocnt = 0, tcnt = 0;
    for (int i = 0; i < n; i++) {
      ocnt += (test[i] == 1);
      tcnt += (test[i] == 2);
    }
    assert(ocnt == n - 1);
    assert(tcnt == 1);
#endif
    cout << steps.size() << '\n';
    for (auto [x, y] : steps) {
      cout << x << ' ' << y << '\n';
    }
  }
}
