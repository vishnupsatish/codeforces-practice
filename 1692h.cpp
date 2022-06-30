/**
 *    author:  vishnus
 *    created: 2022-06-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: My initial thought was a two-pointers method but that won't work because a future decrement/increment
// of a pointer may not be optimal based on a previous change of pointer. We can use Kadane's algorithm to find
// the maximum subarray sum. For a given 'a' value, the subarray sum can be constructed as follows: all elements
// that are equal to 'a' are ones, all other elements are negative ones. This would lead to an O(n^2) runtime, 
// but we can reduce this to O(n) as follows. Instead of constructing the entire array of ones and zeroes, aka
// looping the entire array for every value of 'a', we can just store and loop the indices that 'a' appears in.
// This is because we know that it is always optimal to start and end a subarray at an 'a' value and because 
// all of the other values will just decrease by one, so we can take the difference of indices into account when
// calculating the dp value.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> x(n);
    map<int, vector<int>> idx;
    for (int i = 0; i < n; i++) {
      cin >> x[i];
      idx[x[i]].push_back(i);
    }
    int a = x[0], lans = 0, rans = 0, ans = 1;
    for (const auto &[val, is] : idx) {
      int tot = 1;
      int cur_l = is[0];
      for (int i = 1; i < (int) is.size(); i++) {
        tot++;
        tot -= is[i] - is[i - 1] - 1;
        if (tot > ans) {
          lans = cur_l;
          rans = is[i];
          ans = tot;
          a = val;
        }
        if (tot < 1) {
          cur_l = is[i];
          tot = 1;
        }
      }
    }
    cout << a << ' ' << lans + 1 << ' ' << rans + 1 << '\n';
  }
}
