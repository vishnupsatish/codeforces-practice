/**
*  author:  vishnus
*  created: 2022-08-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: first convert everything in 'a' to a 0 by looping the prefix and if a[i] != a[i + 1],
// then do prefix 'i'. Now prefix 'i' + 1 will contain either all ones or all zeroes. Then, 
// convert all zeroes to 'b' by looping backwards. If the current value != b[i], do prefix 'i'
// and set current value ^= 1. So easy. Just had to think of the converting to zeroes in n 
// operations thing.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != a[i + 1]) {
        ans.push_back(i);
      }
    }
    if (a[n - 1] == '1') {
      ans.push_back(n - 1);
    }
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (cur != (int) (b[i] - '0')) {
        ans.push_back(i);
        cur ^= 1;
      }
    }
    cout << (int) ans.size();
    for (auto an : ans) {
      cout << ' ' << an + 1;
    }
    cout << '\n';
  }
}
