#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;
typedef unsigned long long llu;

const int MAX_N = (int)1e6 + 1;

struct Edge {
  int x, y, w;
  Edge(int x, int y, int w) : x(x), y(y), w(w) {}
};

vector<Edge> edges;
int par[MAX_N];

int find(int n) {
    return par[n] < 0 ? n : par[n] = find(par[n]);
}

void uni(int n, int m) {
    n = find(n), m = find(m);
    if (n == m) return;
    par[n] += par[m];
    par[m] = n;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    memset(par, -1, sizeof(par));
    while (M--) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        edges.emplace_back(x, y, w);
    }
    sort(edges.begin(), edges.end(), [](auto l, auto r) { return l.w > r.w; });

    llu num_edges = 0;
    llu sum = 0;
    for (auto e : edges) {
        int x = find(e.x);
        int y = find(e.y);
        if (x != y) {
            num_edges += (llu)par[x] * par[y];
            uni(x, y);
        }
        (sum += num_edges * e.w) %= (int)1e9;
    }
    printf("%llu", sum);

    return 0;
}