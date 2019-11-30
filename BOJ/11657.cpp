#include <bits/stdc++.h>

using namespace std;

struct Info {
    int st, end, dist;
};

vector<Info> v;
int d[501], vis[501];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    v.resize(M);
    for (auto & i : v) {
        scanf("%d %d %d", &i.st, &i.end, &i.dist);
    }

    fill(d, d + N + 1, 2e9);

    d[1] = 0;
    vis[1] = 1;
    while (M--) {
        for (auto i : v) {
            vis[i.end] |= vis[i.st];
            if (d[i.end] > d[i.st] + i.dist) {
                d[i.end] = d[i.st] + i.dist;
                if (!M && vis[i.end]) return printf("-1"), 0;
            }
        }
    }

    for (int i = 2; i <= N; i++)
        printf("%d\n", vis[i] ? d[i] : -1);

    return 0;
}