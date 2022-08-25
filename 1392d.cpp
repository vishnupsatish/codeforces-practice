/**
*  author:  vishnus
*  created: 2022-08-25
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: there are two illogical substrings, "LLL" and "RRR". We basically have to compress this 
// into (character, length), then do length // 3 and add that to the answer. If the entire string
// is made up of one character, we have to do ceil(n / 3) because the end of the string will be 
// extended by 2 characters from the beginning.

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
    vector<char> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<pair<char, int>> vals;
    char cur = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] != cur) {
        vals.push_back({cur, cnt});
        cnt = 1;
        cur = a[i];
      } else {
        cnt++;
      }
    }
    vals.push_back({cur, cnt});
    if ((int) vals.size() != 1 && vals[0].first == vals[(int) vals.size() - 1].first) {
      vals[0].second += vals[(int) vals.size() - 1].second;
      vals.pop_back();
    }
    if ((int) vals.size() == 1) {
      cout << (vals[0].second + 2) / 3 << '\n';
      continue;
    }
    int ans = 0;
    for (auto [v, ccnt] : vals) {
      ans += ccnt / 3;
    }
    cout << ans << '\n';
  }
}
