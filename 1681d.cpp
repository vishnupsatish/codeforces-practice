/**
 *    author:  vishnus
 *    created: 2022-05-26
**/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx, avx2, fma")

using namespace std;

// Idea: use a recursive algorithm. Two maps, mcnt and done, will track
// the answer for a given value (done) and the minimum count value it 
// took to get there (mcnt). Use those as a memoization method.

int num_digits(long long x) {
  if (x < 10) {
    return 1;
  }
  if (x < 100) {
    return 2;
  }
  if (x < 1000) {
    return 3;
  }
  if (x < 10000) {
    return 4;
  }
  if (x < 100000) {
    return 5;
  }
  if (x < 1000000) {
    return 6;
  }
  if (x < 10000000) {
    return 7;
  }
  if (x < 100000000) {
    return 8;
  }
  if (x < 1000000000) {
    return 9;
  }
  if (x < 10000000000) {
    return 10;
  }
  if (x < 100000000000) {
    return 11;
  }
  if (x < 1000000000000) {
    return 12;
  }
  if (x < 10000000000000) {
    return 13;
  }
  if (x < 100000000000000) {
    return 14;
  }
  if (x < 1000000000000000) {
    return 15;
  }
  if (x < 10000000000000000) {
    return 16;
  }
  if (x < 100000000000000000) {
    return 17;
  }
  if (x < 1000000000000000000) {
    return 18;
  }
  return 19;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long x;
  cin >> n >> x;
  unordered_map<long long, int> done, mcnt;
  int mans = 1e9;
  function<int(long long, int)> Do = [&](long long c, int cnt) -> int {
    if (cnt >= mans) {
      return 1e9;
    }
    if (mcnt.find(c) != mcnt.end() && mcnt[c] <= cnt) {
      return done[c];
    }
    if (num_digits(c) == n) {
      mans = min(mans, cnt);
      mcnt[c] = cnt;
      return done[c] = cnt;
    }
    int ans = 1e9;
    long long cn = c;
    do {
      int ei = cn % 10;
      cn /= 10;
      if (ei > 1) {
        ans = min(ans, Do(c * ei, cnt + 1));
      }
    } while (cn > 0);
    mcnt[c] = cnt;
    return done[c] = ans;
  };
  int ans = Do(x, 0);
  cout << (ans == 1e9 ? -1 : ans) << '\n';
}
