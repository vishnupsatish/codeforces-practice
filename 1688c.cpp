/**
 *    author:  vishnus
 *    created: 2022-06-05
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: given a letter c, if it appears an odd number of times in all of T and the resulting
// string, it will be the answer. Why? Imagine a letter is not the initial letter. Then it will
// appear in either an odd number of T values and the resulting string. Basically, for every occurrence
// of c, it will either be replaced (multiplying it by 2) or it will show up in the resulting
// string (multiplying it by 2). Or it will appear an even number of times in T, being fully 
// replaced and gone by the time of the resulting string.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int op;
    cin >> op;
    vector<string> t(op * 2);
    unordered_map<char, int> cnt;
    for (int i = 0; i < op * 2; i++) {
      cin >> t[i];
      for (auto e : t[i]) {
        cnt[e]++;
      }
    }
    string s;
    cin >> s;
    for (auto e : s) {
      cnt[e]++;
    }
    for (auto [k, v] : cnt) {
      if (v & 1) {
        cout << k << '\n';
        break;
      }
    }
  }
}
