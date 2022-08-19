/**
 *    author:  vishnus
 *    created: 2022-08-19
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if (n, n) is a winning position, then it is Utkarsh who wins from there and he can guide
// the it to that point. Otherwise, find (n, m) such that abs(n - m) is minimized. Whoever wins
// from that position wins the game. Why? If Utkarsh wins, he can go to greatest (n, n) then Ashish
// has no choice but to get led to (n, m). If Ashish wins, Utkarsh's initial thing of going up
// two in a row is countered because then he will be 'k' away from the middle x and can force his
// way to (n, m).

struct Point {
  int x, y;
};

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    long long d, k;
    cin >> d >> k;
    vector<Point> w; // Winning positions
    unordered_map<int, int> mpy; // Maps y -> x for winning positions
    for (long long x = 0; x < d; x += k) {
      int y = (int) sqrt(d * d - x * x);
      mpy[y - (y % k)] = x;
    }
    string win;
    auto WhoWins = [&](int x, int y) {
      if ((x + y) / k & 1) {
        return "Ashish";
      }
      return "Utkarsh";
    };
    for (auto [y, x] : mpy) {
      w.push_back({x, y});
    }
    int mi = 1e9;
    for (auto [x, y] : w) {
      if (abs(x - y) < mi) {
        mi = abs(x - y);
        win = WhoWins(x, y);
      }
    }
    cout << win << '\n';
  }
}
