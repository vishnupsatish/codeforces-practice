/**
*  author:  vishnus
*  created: 2022-08-24
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: loop the number of swords we take (assume s < w) then greedily complete and check the rest.

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false);
  cin.tie(0);
#endif
  int tt;
  cin >> tt;
  while (tt--) {
    long long p, f;
    cin >> p >> f;
    int cs, cw;
    cin >> cs >> cw;
    long long s, w;
    cin >> s >> w;
    if (s > w) {
      swap(cs, cw);
      swap(s, w);
    }
    // s will always be less than w
    long long ans = 0;
    for (int i = 0; i <= cs; i++) { // Make 'p' have 'i' of the first item - everything else can be greedily calculated
      long long curs = cs;
      long long curw = cw;
      long long curp = p;
      long long curf = f;
      long long curans = i;
      curp -= i * s;
      if (curp < 0) {
        break;
      }
      curs -= i;
      long long tk1 = min(curw, curp / w);
      curp -= min(curw * w, w * (curp / w));
      curw = max(0ll, curw - tk1);
      curans += tk1;
      long long tk2 = min(curs, curf / s);
      curf -= min(curs * s, s * (curf / s));
      curs = max(0ll, curs - tk2);
      curans += tk2;
      long long tk3 = min(curw, curf / w);
      curf -= min(curw * w, w * (curf / w));
      curw = max(0ll, curw - tk3);
      curans += tk3;
      ans = max(ans, curans);
    }
    cout << ans << '\n';
  }
}
