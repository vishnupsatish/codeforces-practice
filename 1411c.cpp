/**
*  author:  vishnus
*  created: 2022-08-23
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: build a graph so that if a rook is at (x, y) make x -> y an edge. First of all, all
// self loops can be removed. Next, if there is a path that is not a cycle, then take the first
// node of that path and move it to (x, x) since it is known that there is nothing in the y-coordinate
// since there is no edge that connects to the 'x' value of that node. If there is a cycle, one
// of the nodes must be moved to an irrelevant position and the same thing must happen, so the
// answer is just the number of nodes + the number of cycles.

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
    int n, m;
    cin >> n >> m;
    vector<Point> a;
    vector<int> nxt(n, -1);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (x != y) {
        a.push_back({x, y});
        nxt[x] = y;
      }
    }
    vector<int> vis(n);
    int cyc = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i] && nxt[i] != -1) {
        int cur = i;
        do {
          vis[cur] = 1;
          cur = nxt[cur];
        } while (cur != i && cur != -1 && vis[cur] != 1);
        if (cur == i) {
          cyc++;
        }
      }
    }
    cout << (int) a.size() + cyc << '\n';
  }
}
