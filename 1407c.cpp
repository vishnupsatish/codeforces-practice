/**
 *    author:  vishnus
 *    created: 2022-04-26
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: if a mod b > b mod a, then a < b. Why? u mod v = u if u < v, and v mod u 
// can never exceed u. Therefore, it stands. Keep a variable of the maximum element
// so far, and loop starting from the second element. Query max index, i and 
// vice-versa. Update max index and ans[i] accordingly. Eventually, all that is 
// left is the greatest element.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [](int P, int Q) -> int {
    cout << "? " << P + 1 << ' ' << Q + 1 << endl;
    int k;
    cin >> k;
    return k;
  };
  vector<int> a(n);
  int mx = 0;
  for (int i = 1; i < n; i++) {
    int a1 = Ask(mx, i);
    int a2 = Ask(i, mx);
    if (a1 < a2) {
      a[i] = a2;
    } else {
      a[mx] = a1;
      mx = i;
    }
  }
  a[mx] = n;
  cout << "! ";
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}
