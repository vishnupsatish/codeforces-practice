/**
 *    author:  vishnus
 *    created: 2022-04-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we know that when we encounter an a[i] such that a[i] > a[i - 1], we can
// just make it a sibling of a[i - 1], since it follows the "in ascending order"
// condition of siblings. Otherwise, we can greedily make it the child of the 
// next node in the same level. Then if a[i] > a[i - 1] just make it the sibling
// of a[i - 1]. Then, if a[i] < a[i - 1] and we've run out of nodes, increment the level.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int lvl = 1;
    vector<int> lcnt(n), totcnt(n);
    lcnt[0] = 1;
    for (int i = 2; i < n; i++) {
      totcnt[lvl]++;
      if (a[i] < a[i - 1]) {
        lcnt[lvl]++;
        if (lcnt[lvl] >= totcnt[lvl - 1]) {
          lvl++;
        }
      }
    }
    cout << lvl << '\n';
  }
}
