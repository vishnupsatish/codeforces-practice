/**
 *    author:  vishnus
 *    created: 2022-05-06
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: Greedy. We want to distribute the smallest letter to all strings. If there are less occurrences
// of the smallest letter than strings, the answer is the kth character is the sorted string since we want
// to assign the rest of the other characters with the smallest character. If there is only one type of
// letter, we want to distribute equally. If we have more occurrences of the smallest letter than there
// are strings, we want to assign all other letters to one string which will contain all of the remaining
// occurrences of the smallest letter (once all other strings have exactly one occurrence). Why? We must
// assign the other characters in *some* way and we don't want the later characters to come earlier in a
// string, so we pad it with as many early characters as we can. If k == the number of occurrences of the
// smallest character and there are only two unique characters, the prefix rule comes into effect. Equally
// distribute all occurrences of the second-least character equally across all strings. We don't want all
// of them to go to one string since in contrast to the correct method, the correct method would produce
// prefixes of the method described.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto e : s) {
      cnt[e]++;
    }
    sort(s.begin(), s.end());
    if ((int) cnt.size() == 1) {
      int cc = ceil((double) n / (double) k);
      for (int i = 0; i < cc; i++) {
        cout << (*cnt.begin()).first;
      }
      cout << '\n';
      continue;
    }
    if (k > (*cnt.begin()).second) {
      cout << s[k - 1] << '\n';
      continue;
    }
    if (k == 1) {
      cout << s << '\n';
      continue;
    }
    if (k < (*cnt.begin()).second) {
      cout << s.substr(k - 1, n - k + 1) << '\n';
      continue;
    }
    if (k == (*cnt.begin()).second) {
      if ((int) cnt.size() == 2) {
        cout << s[0];
        char cur = (*(next(cnt.begin()))).first;
        int curcnt = (*(next(cnt.begin()))).second;
        int cc = ceil((double) curcnt / (double) k);
        for (int i = 0; i < cc; i++) {
          cout << cur;
        }
        cout << '\n';
      } else {
        cout << s.substr(k - 1, n - k + 1) << '\n';
      }
    }
  }
}
