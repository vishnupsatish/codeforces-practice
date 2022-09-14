/**
*  author:  vishnus
*  created: 2022-09-14
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: just loop from 1 -> 50. Query i, i + 1 and i + 1, i. If two queries aren't equal, the sum is
// the answer since they cover the entire graph. Otherwise, continue the loop. If answer is -1, output i - 1.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto Ask = [&](int A, int B) {
    cout << "? " << A << ' ' << B << endl;
    long long val;
    cin >> val;
    return val;
  };
  for (int i = 1; i <= 50; i++) {
    long long v1 = Ask(i, i + 1);
    long long v2 = Ask(i + 1, i);
    if (v1 == -1) {
      cout << i - 1 << endl;
      break;
    }
    if (v1 != v2) {
      cout << "! " << v1 + v2 << endl;
      break;
    }
  }
}
