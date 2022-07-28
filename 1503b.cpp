/**
 *    author:  vishnus
 *    created: 2022-07-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: two diagonals; place ones in the first and twos in the second. If one of them runs out, either place the respective number in the other diagonal or a three in the other diagonal, based on the 'a' value.

struct Position {
  int i;
  int j;
};

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int n;
  cin >> n;
#ifndef ONLINE_JUDGE
  vector<vector<int>> vals(n, vector<int>(n));
#endif
  auto Play = [&](int b, int i, int j) {
#ifndef ONLINE_JUDGE
    assert(i < n);
    assert(j < n);
    assert(i >= 0);
    assert(j >= 0);
    assert(vals[i][j] == 0);
    vals[i][j] = b;
#endif
    cout << b << ' ' << i + 1 << ' ' << j + 1 << endl;
  };
  auto Get = [&]() {
    int a;
    cin >> a;
    return a;
  };
  auto NextPosition = [&](Position &pos, int &nv) {
    int &i = pos.i;
    int &j = pos.j;
    if (i != n - 1 && j != n - 1) {
      i++;
      j++;
      return;
    }
    if (j == n - 1 && i == n - 1) {
      j = 2;
      nv = 4;
      i = 0;
      return;
    }
    if (i == n - 1 && j == n - 2) {
      j = 1;
      nv = 3;
      i = 0;
      return;
    }
    if (i == n - 1) {
      i = nv;
      j = 0;
      nv -= 2;
      return;
    }
    if (j == n - 1) {
      i = 0;
      j = nv;
      nv += 2;
      return;
    }
  };
  auto Done = [&](Position pos) {
    if (pos.i >= n || pos.j >= n) {
      return true;
    }
    if (pos.i < 0 || pos.j < 0) {
      return true;
    }
    return false;
  };
  // Values for first and second diagonal
  Position fd = {n - 1, 0};
  Position sd = {n - 2, 0};
  int nxt_fd = n - 3;
  int nxt_sd = n - 4;
  // Place 1 in first diagonal, 2 in second, 3 in whatever diagonal is not done
  for (int m = 0; m < n * n; m++) {
    int a = Get();
    if (a == 1) {
      // Second diagonal is done! Place 3 in first diagonal
      if (Done(sd)) {
        Play(3, fd.i, fd.j);
        NextPosition(fd, nxt_fd);
      } else {
        Play(2, sd.i, sd.j);
        NextPosition(sd, nxt_sd);
      }
    } else if (a == 2) {
      // First diagonal is done! Place 3 in second diagonal
      if (Done(fd)) {
        Play(3, sd.i, sd.j);
        NextPosition(sd, nxt_sd);
      } else {
        Play(1, fd.i, fd.j);
        NextPosition(fd, nxt_fd);
      }
    } else {
      // First diagonal is done! Place 2 in second diagonal.
      if (Done(fd)) {
        Play(2, sd.i, sd.j);
        NextPosition(sd, nxt_sd);
      } else {
        Play(1, fd.i, fd.j);
        NextPosition(fd,nxt_fd);
      }
    }
  }
#ifndef ONLINE_JUDGE
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<pair<int, int>> adj = {{i - 1, j}, {i, j - 1}, {i + 1, j}, {i, j + 1}};
      for (auto e : adj) {
        if (e.first >= 0 && e.first < n && e.second >= 0 && e.second < n) {
          assert(vals[e.first][e.second] != vals[i][j]);
        }
      }
    }
  }
#endif
}
