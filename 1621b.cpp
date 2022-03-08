#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Greedy. You can either choose one or two things to buy. Why would it be optimal to do otherwise?


void solve() {
    int n;
    cin >> n;

    auto cmp_all = [] (tuple<int, int, int> fst, tuple<int, int, int> snd) -> bool {
        int l1 = get<0>(fst);
        int l2 = get<0>(snd);
        int r1 = get<1>(fst);
        int r2 = get<1>(snd);
        int c1 = get<2>(fst);
        int c2 = get<2>(snd);
        if (l1 == l2 && r1 == r2) {
            return c1 < c2;
        }

        if (l1 == l2) {
            return r1 > r2;
        }

        return l1 < l2;
    };

    set<tuple<int, int, int>> st; // Start <position, cost, number>
    set<tuple<int, int, int>> en; // End <position, cost, number> (negative position to ensure sorting is reverse for position)
    set<tuple<int, int, int>, decltype(cmp_all)> on(cmp_all); // All <start, end, cost>

    // First try to combine two then see if just doing one will be better

    for (int i = 1; i <= n; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        st.emplace(l, c, i);
        en.emplace(-r, c, i);
        on.emplace(l, r, c);

        int l1 = get<0>(*st.begin());
        int r1 = -get<0>(*en.begin());
        int c1 = get<1>(*st.begin());
        int c2 = get<1>(*en.begin());
        int ls1 = get<0>(*on.begin());
        int rs1 = get<1>(*on.begin());
        int cs1 = get<2>(*on.begin());

        if (ls1 == l1 && rs1 == r1 && cs1 <= c1 + c2) {
            cout << cs1 << '\n';
        } else {
            cout << c1 + c2 << '\n';
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}

