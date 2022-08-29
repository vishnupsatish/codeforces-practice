/**
*  author:  vishnus
*  created: 2022-08-29
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if t <= the average, the answer is always 2, 4, 6, 8, etc. since we want to do the 
// same amount of hot cups as cold cups. Otherwise, there is a simple average formula we can
// use, round up and round down, try both, and see which is better.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    long double h, c, t;
    cin >> h >> c >> t;
    long double avg = (h + c) / 2.0;
    if (t <= avg) {
      cout << 2 << '\n';
      continue;
    }
    long double a1 = ceil(((t - h) / (h + c - 2 * t)) + (long double) 1);
    long double a2 = floor(((t - h) / (h + c - 2 * t)) + (long double) 1);
    long double dif1 = t - ((h * a1 + c * (a1 - 1)) / (2 * a1 - 1));
    long double dif2 = t - ((h * a2 + c * (a2 - 1)) / (2 * a2 - 1));
    if (abs(dif1) < abs(dif2)) {
      cout << a1 * 2 - 1 << '\n';
    } else {
      cout << a2 * 2 - 1 << '\n';
    }
  }
}
