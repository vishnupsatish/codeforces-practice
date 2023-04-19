#include <bits/stdc++.h>

using namespace std;

// Idea: a singular inversion is just a simple swap of indices i, i + 1. Create a graph from i -> p[i]
// for each index i. This maps how many total swaps to do to get a permutation in order. NOW, to get A
// SINGULAR INVERSION, we would either need one less or one greater swap. Breaking up a cycle into two
// decreases the number of swaps to do by one. So, the idea is to swap two adjacent numbers, i and i + 1.
// So if a cycle contains i and i + 1, that means we can alter the swaps to get one less. As in, if an
// edge i -> k exists, make it i + 1 -> k. We know k ->->-> i + 1 exists due to the cyclic nature, so
// the graph can be split there. Same thing for i + 1 -> j. So that creates one less component and we
// can subtract one from the overall answer.

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
      --a[i];
    }
    vector<int> vis(n);
    int ans = 0;
    int flag = 1;
    for (int i = 0; i < n; i++) {
      unordered_set<int> ag;
      if (!vis[i]) {
        ag.insert(i);
        vis[i] = 1;
        int lth = 1;
        int cur = a[i];
        while (!vis[cur]) {
          ag.insert(cur);
          vis[cur] = 1;
          cur = a[cur];
          lth++;
        }
        for (auto e : ag) {
          if (ag.contains(e + 1)) {
            flag = -1;
          }
        }
        ans += lth - 1;
      }
    }
    cout << ans + flag << '\n';
  }
}
