/**
 *    author:  vishnus
 *    created: 2022-03-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: use modular arithmetic. If the GCD is not 1 of i and n, then you 
// can't add it to the answer (i.e the numbers are not coprime) because 
// the product will not be coprime and the modulo therefore will not be 
// coprime. Then, we take the mod. If it is 1, we are done. Otherwise, we 
// need to remove the mod value from the answer since it is coprime and 
// is guaranteed to exist in the remaining numbers.

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  set<long long> ans;
  for (int i = 1; i < n; i++) {
    if (gcd(i, n) == 1) {
      ans.insert(i);
    }
  }
  long long m = 1;
  for (auto &e : ans) {
    m *= e;
    m %= n;
  }
  if (m != 1) {
    ans.erase(m);
  }
  cout << (int) ans.size() << '\n';
  for (auto &e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
}
