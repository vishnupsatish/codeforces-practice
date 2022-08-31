/**
*  author:  vishnus
*  created: 2022-08-30
**/
#include <bits/stdc++.h>

using namespace std;

// Idea: 2/3 number of queries as contestants is what we need. So, the goal should be for every two queries
// remove three people. How can we do that? Using divide and conquer. Query 1, 3. If 1 wins, we know that 
// 2 and 3 cannot win, so query 1, 4 and move the winner forward. Do the same for all other results. It is
// self-explanatory as to why this works. There is another algorithm that doesn't work; it pushes both the
// possible winners to the next level. But there is an issue with this. It is also an example of divide 
// and conquer but the intermediate steps in d&c must also be correct, in this case it isn't because say 
// we have '1 0 2 0'. It will push the '0 2' to the next step which is obviously incorrect, then afterwards
// it might perform incorrect steps because the algorithm assumes that when player 1 beats player 3, it 
// has gone to the next level since both players 1 and 3 are on the same level, which is not the case when
// you use the incorrect algorithm.

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
    auto Query = [&](int a, int b) {
      cout << "? " << a + 1 << ' ' << b + 1 << endl;
      int w;
      cin >> w;
      return w;
    };
    vector<int> nxt;
    for (int i = 0; i < (1 << n); i++) {
      nxt.push_back(i);
    }
    while ((int) nxt.size() >= 4) {
      vector<int> fn;
      for (int i = 0; i < (int) nxt.size(); i += 4) {
        int res = Query(nxt[i], nxt[i + 2]);
        if (res == 1) {
          if (Query(nxt[i], nxt[i + 3]) == 1) {
            fn.push_back(nxt[i]);
          } else {
            fn.push_back(nxt[i + 3]);
          }
        } else if (res == 2) {
          if (Query(nxt[i + 1], nxt[i + 2]) == 1) {
            fn.push_back(nxt[i + 1]);
          } else {
            fn.push_back(nxt[i + 2]);
          }
        } else {
          if (Query(nxt[i + 1], nxt[i + 3]) == 1) {
            fn.push_back(nxt[i + 1]);
          } else {
            fn.push_back(nxt[i + 3]);
          }
        }
      }
      nxt = fn;
    }
    int fres = Query(nxt[0], nxt[1]);
    if (fres == 1) {
      cout << "! " << nxt[0] + 1 << endl;
    } else {
      cout << "! " << nxt[1] + 1 << endl;
    }
  }
}
