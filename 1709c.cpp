/**
*  author:  vishnus
*  created: 2022-08-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: there should be no ambiguity of what to place at certain '?' positions. First and last
// positions are self-explanatory. Now, iterate the string. If the stk_cnt value is <= 0 and
// there are exactly abs(stk_cnt) + 1 question marks behind the current position, then all of
// those question marks must be opening brackets since otherwise, the stk_cnt value would
// be negative rendering the sequence invalid. We know that these are the only places that we
// have to place opening brackets and every other position will consist of closing brackets.
// If this is the case, then the answer is 'yes'.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    deque<int> idx;
    for (int i = 1; i < n - 1; i++) {
      if (s[i] == '?') {
        idx.push_back(i);
      }
    }
    int val = 1;
    s[0] = '(';
    for (int i = 1; i < n - 1; i++) {
      if (s[i] == '(') {
        val++;
      } else if (s[i] == ')') {
        val--;
      }
      int gt = upper_bound(idx.begin(), idx.end(), i) - idx.begin();
      if (abs(val) + 1 == gt && val <= 0) {
        for (int j = 0; j < gt; j++) {
          s[idx.front()] = '(';
          idx.pop_front();
          val++;
        }
      }
    }
    val--;
    s[n - 1] = ')';
    val = abs(val);
    int tot = 0;
    for (int i = 1; i < n - 1; i++) {
      tot += (s[i] == '?');
    }
    cout << (tot == val ? "YES" : "NO") << '\n';
  }
}
