/**
 *    author:  vishnus
 *    created: 2022-05-12
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: we can model it as a connected graph (any nodes not connected can just be added at the 
// end). If any node has more than two adjacent nodes, there is no answer. Otherwise, we find 
// one node that has one adjacent (must be such a node) and we start the sequence at that node.
// Then, we continue as per the adjacency list.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    if (n == 1) {
      cout << "YES" << '\n';
      cout << s;
      for (int i = 0; i < 26; i++) {
        if ((char) (i + 'a') != s[0]) {
          cout << (char) (i + 'a');
        }
      }
      cout << '\n';
      continue;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      a[i] = s[i] - 'a';
    }
    vector<unordered_set<int>> adj(26);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        adj[a[i - 1]].insert(a[i]);
        adj[a[i]].insert(a[i - 1]);
      }
      if (i < n - 1) {
        adj[a[i + 1]].insert(a[i]);
        adj[a[i]].insert(a[i + 1]);
      }
      if ((int) adj[a[i]].size() > 2) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    vector<int> done(26);
    int t = -1;
    for (int i = 0; i < 26; i++) {
      if ((int) adj[i].size() == 1) {
        t = i;
      }
    }
    if (t == -1) {
      cout << "NO" << '\n';
      continue;
    }
    string ans;
    while (true) {
      if (done[t]) {
        break;
      }
      done[t] = 1;
      ans.push_back((char) (t + 'a'));
      if (adj[t].size() == 2) {
        int fst = *adj[t].begin();
        int sec = *next(adj[t].begin());
        if (done[fst] && done[sec]) {
          break;
        }
        if (done[fst]) {
          t = sec;
        } else {
          t = fst;
        }
      } else {
        t = *adj[t].begin();
      }
    }
    for (int i = 0; i < 26; i++) {
      if (!done[i]) {
        ans.push_back((char) (i + 'a'));
      }
    }
    cout << "YES" << '\n';
    cout << ans << '\n';
  }
}
