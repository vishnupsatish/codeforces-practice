/**
 *    author:  vishnus
 *    created: 2022-05-04
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: max sum will be go down then right, min sum will be down right then down. We
// can make anything in between. How? To make min + 1, we can go right to the second-rightmost
// place, the down, then right again. Since diagonals increase starting from the top-right,
// doing this will increase the min sum by one. We can utilize this strategy recursively.
// Now, how can we determine how many sums there are? This is based on the number of opportunities
// to increase the sum from the min sum. We can think about it as bending a path at the
// first possible place or we can think of it as, at corresponding places, how much is the
// max sum contributor greater by (diagonals)? 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long x0, y0, x2, y2;
    cin >> x0 >> y0 >> x2 >> y2;
    cout << (x2 - x0) * (y2 - y0) + 1 << '\n';
  }
}
