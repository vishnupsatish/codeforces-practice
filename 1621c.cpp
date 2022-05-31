/**
 *    author:  vishnus
 *    created: 2022-05-31
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if the entire permutation is a cycle, we just query '1' continuously,
// and the previous number returned gives us the index of the value of the current
// number in 'p' (if the index queried is the same). Why? Imagine we have p = 3 1 4 2.
// q1 = 1 2 3 4. q2 = 3 1 4 2. q3 = 4 3 2 1. q4 = 2 4 1 3. When we keep querying 1, we
// receive 1, p(1), p(p(1)), etc. But, there might be some cycles. So loop all possible
// indices then keep querying until we receive the first element we received when we
// queried. Then, move on to the next index.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto Ask = [](int i) {
      cout << "? " << i + 1 << endl;
      int x;
      cin >> x;
      --x;
      return x;
    };
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
      if (p[i] != -1) {
        continue;
      }
      deque<int> queries;
      while (true) {
        int q = Ask(i);
        queries.push_back(q);
        if ((int) queries.size() > 1 && queries.back() == queries.front()) {
          break;
        }
      }
      for (int j = 1; j < (int) queries.size(); j++) {
        p[queries[j - 1]] = queries[j];
      }
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << p[i] + 1;
    }
    cout << endl;
  }
}
