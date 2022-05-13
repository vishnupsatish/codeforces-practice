/**
 *    author:  vishnus
 *    created: 2022-05-13
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: think in terms of modulo. Separate all numbers from 0 to q (since q is the 
// maximum possible answer) based on their value mod x. Then, given a query y, we 
// can only add or subtract x so we cannot greedily remove the smallest number, we 
// must greedily remove the smallest number that is congruent to y (mod x). Then, 
// we can use another set to calculate the answer based on that.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q, x;
  cin >> q >> x;
  unordered_map<int, set<int>> a;
  set<int> al;
  for (int i = 0; i <= q; i++) {
    a[i % x].insert(i);
    al.insert(i);
  }
  while (q--) {
    int y;
    cin >> y;
    if (!a[y % x].empty()) {
      al.erase(*a[y % x].begin());
      a[y % x].erase(a[y % x].begin());
    }
    cout << *al.begin() << '\n';
  }
}
