/**
 *    author:  vishnus
 *    created: 2022-05-08
**/
#include <bits/stdc++.h>

using namespace std;

// Ensure that all the values (a[i] + i) % n are unique. If they are, the answer is 
// "yes". Why? If two mod values are the same, meaning i + a[i] == j + a[j] (mod n),
// then i + a[i] = j + a[j] + kn for some k, meaning the uniqueness is lost. Why? 
// Simple modular arithmetic. It also ensures that no rooms are vacant. 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_set<int> md;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] += i;
      md.insert((a[i] % n + n) % n);
    }
    cout << ((int) md.size() == n ? "YES" : "NO") << '\n';
  }
}
