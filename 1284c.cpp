/**
 *    author:  vishnus
 *    created: 2022-05-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: loop r - l (let that be 'i'). We know that i + 1 is the length of the
// current sequence. A framed sequence must be a permutation of its length EXCEPT
// its starting number can range anywhere from 1 to the length of the entire 
// permutation - i. We can therefore find all arrangements a framed 
// sequence of length i + 1, find all arrangements of all of the other numbers
// (using factorial), find all of the possible starting numbers (from 1 to n - i)
// and all possible positions to place this framed sequence (from 1 to n - i). 
// Multiplying these gives the answer for a given r - l.

long long memo[250010];

long long fact(long long numb, int md) {
  if (numb == 1 || numb == 0) {
    return 1;
  }
  if (memo[numb] != 0) {
    return memo[numb];
  }
  return memo[numb] = (numb * fact(numb - 1, md)) % md;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 0; i < n; i++) { // Loop r - l
    long long wsm = n - i; // We can do 123, 234, etc all the way to n
    long long wpos = n - i; // Number of positions to place the sequence
    long long cnt = (((wsm * wpos) % m * (fact(i + 1, m)) % m) * fact(n - i - 1, m)) % m;
    ans += cnt;
    ans %= m;
  }
  cout << ans << '\n';
}
