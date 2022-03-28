/**
 *    author:  vishnus
 *    created: 2022-03-28
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: choose some prefix of the string and duplicate/reduce its length to make its 
// length equal to k. If an element is greater than the first, end the prefix there. 
// If an element is equal to the first, check whether the continuation of that element
// is less than or greater than the continuation of the first element.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ind = -1;
  for (int i = 1; i < n; i++) {
    if (s[i] > s[0]) {
      ind = i;
      break;
    } else if (s[i] == s[0]) {
      int cind = i;
      int len = i;
      bool ok = false;
      while (cind < n) {
        if (s[cind] == s[cind % len]) {
          cind++;
        } else if (s[cind] > s[cind % len]) {
          ok = true;
          break;
        } else {
          break;
        }
      }
      if (cind == n) {
        ok = true;
      }
      if (ok) {
        ind = i;
        break;
      }
    }
  }
   if (ind != -1) {
    s = s.substr(0, ind);
  }
  n = (int) s.size();
  if (k < n) {
    s = s.substr(0, k);
  } else {
    int cind = 0;
    while ((int) s.size() < k) {
      s += s[cind++ % n];
    }
  }
  cout << s << '\n';
}
