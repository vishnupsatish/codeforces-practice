/**
 *    author:  vishnus
 *    created: 2022-05-27
**/
#include <bits/stdc++.h>

using namespace std;

// The number of equilateral triangles is given by 2 times the number of intersections
// at the centre of a given hexagon. There are three different slopes that we can use.
// When we add a new line, the goal is to make it intersect at the centre of a hexagon
// with every other slope. We should also place all three slopes alternatively, then
// repeat. Why? Imagine we don't do this and two slopes have a line count difference
// of two. If we were to move one line from this slope to the slope with two less, the
// number of intersections with the third slope stays the same, and the intersections
// reduces by the number of lines in the smaller group and increases by the original
// number of the lines in the larger group - 1. Since largest group - smallest group
// >= 2, the answer is bound to increase by at least one. By adding a line, the number
// of intersections increases by the sum of the number of lines in each of the two
// other slopes. For each line, this will look as follows: 0, 1, 2, 2, 3, 4, 4, 5, 6, etc.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  vector<long long> its(100000), tri(100000); // Number of triangles formed by i + 1 lines
  int cur = 0;
  its[0] = cur;
  for (int i = 1; i < 100000; i++) {
    cur += (i % 3 != 0);
    its[i] = its[i - 1] + cur;
    tri[i] = its[i] * 2;
  }
  while (tt--) {
    int n;
    cin >> n;
    cout << lower_bound(tri.begin(), tri.end(), n) - tri.begin() + 1 << '\n';
  }
}
