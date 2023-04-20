#include <bits/stdc++.h>

using namespace std;

// Idea: it is obvious that this problem requires a graph. The graph must be optimized since a brute force
// one would be too large. An initial thought I had was connect all prime factors that share connections
// through numbers together, but that would have too many edges (since there are so many prime numbers
// and each number can have up to logN prime numbers, and we have to make adjacent every single pair in
// each list of prime factors) - that would cause a memory issue. So the idea is to create a bipartite
// graph. First part (left) is all the indices, second part (right) is all the prime numbers. We connect
// an index to a prime number if it is divisible by that prime. This would lead to a valid answer that
// doesn't take up too much memory - start at node s, end at node t.

const int maxa = 3e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int s, t;
  cin >> s >> t;
  --s; --t;
  if (s == t) {
    cout << 1 << '\n' << s + 1 << '\n';
    return 0;
  } else if (gcd(a[s], a[t]) != 1) {
    cout << 2 << '\n' << s + 1 << ' ' << t + 1 << '\n';
    return 0;
  }
  // Prime factor in O(log N) using spf method
  vector<int> spf(maxa + 1, -1);
  for (int i = 0; i <= maxa; i++) {
    spf[i] = i;
  }
  for (int i = 2; i * i <= maxa; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= maxa; j += i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
  unordered_map<int, unordered_set<int>> ra, ba; // Red is value to pf, blue is pf to value
  for (int i = 0; i < n; i++) {
    int cur = a[i];
    while (cur != 1) {
      ra[i].insert(spf[cur]);
      ba[spf[cur]].insert(i);
      cur /= spf[cur];
    }
  }
  queue<pair<int, int>> q;
  vector<int> vr(maxa + 1), vb(maxa + 1);
  vector<int> pr(maxa + 1, -1), pb(maxa + 1, -1);
  q.emplace(s, 1);
  vb[s] = 1;
  bool done = false;
  while (!q.empty()) {
    int u = q.front().first;
    int red = q.front().second;
    q.pop();
    if (red) {
      for (auto v : ra[u]) {
        if (!vr[v]) {
          vr[v] = 1;
          pr[v] = u;
          q.emplace(v, 0);
        }
      }
    } else {
      for (auto v : ba[u]) {
        if (!vb[v]) {
          vb[v] = 1;
          pb[v] = u;
          if (v == t) {
            done = true;
            break;
          }
          q.emplace(v, 1);
        }
      }
      if (done) {
        break;
      }
    }
  }
  if (!done) {
    cout << -1 << '\n';
  } else {
    vector<int> pth;
    int cur = t;
    int v = true;
    while (cur != -1) {
      if (v) {
        pth.push_back(cur);
        cur = pb[cur];
      } else {
        cur = pr[cur];
      }
      v = !v;
    }
    reverse(pth.begin(), pth.end());
    cout << pth.size() << '\n';
    for (auto e : pth) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}
