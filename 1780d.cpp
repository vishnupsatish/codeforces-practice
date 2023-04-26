#include <bits/stdc++.h>

using namespace std;

// Editorial NOT used!!!

// Idea: initial idea is to go bit-by-bit to determine which bits are set and
// which aren't. Subtract 1. If the number of bits was reduced by 1, that bit
// is set. Otherwise, that bit isn't set and we can use the difference in the
// number of bits to determine which is the next set bit. Now, the question is,
// how do we know when to end? The idea is, make all previous bits 0 at every
// move by subtracting all the current set bits (so only future bits are set).
// When we reach the point where only one bit in the future is set, once the
// operation has finished, stop the algorithm and output the value.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int cnt;
    cin >> cnt;
    auto Query = [&](int q) {
      cout << "- " << q << endl;
      int nv;
      cin >> nv;
      return nv;
    };
    int cur = 0; // What is the location of the only set bit?
    bitset<30> val;
    int oval = 0;
    int ta = 0;
    while (cur <= 30) {
      int nv = Query((1 << cur) | oval);
      nv += ta;
      if (nv < cnt) { // 'cur'th bit set
        cnt = nv;
        val[cur] = 1;
        if (nv - ta == 0) {
          break;
        }
        oval = 0;
        cur++;
      } else { // 'cur'th bit NOT set
        int dif = nv - cnt;
        val[cur + dif + 1] = 1;
        if (nv - ta == 0) {
          break;
        }
        if (cnt - ta == 1) {
          break;
        }
        oval = ((1 << (dif + 1)) - 1) << cur;
        ta += __builtin_popcount(oval);
        cur += dif + 2;
        cnt = nv;
      }
    }
    cout << "! " << val.to_ulong() << endl;
  }
}
