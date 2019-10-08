#include <bits/stdc++.h>
#define f(i, a, b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N = 5e2 + 5, M = 5e3 + 5;
int n, m, s, t;
int fa[N];

struct Edge {
    int u, v, w;

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
} e[M];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m) {
        f(i, 0, m - 1)cin >> e[i].u >> e[i].v >> e[i].w;
        cin >> s >> t;
        sort(e, e + m);
        int fz = -1, fm;
        f(i, 0, m - 1) {
            f(j, 1, n)fa[j] = j;
            f(j, i, m - 1) {
                fa[find(e[j].u)] = fa[find(e[j].v)];
                if (~fz && e[j].w * 1.0 / e[i].w > fz * 1.0 / fm)break;
                if (find(s) == find(t)) {
                    fz = e[j].w, fm = e[i].w;
                    break;
                }
            }
        }
        if (!~fz)puts("IMPOSSIBLE");
        else {
            int g = __gcd(fz, fm);
            fz /= g, fm /= g;
            if (fm == 1)cout << fz << endl;
            else cout << fz << '/' << fm << endl;
        }
    }
    return 0;
}